/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yumamur <yumamur@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 21:02:15 by yumamur           #+#    #+#             */
/*   Updated: 2024/05/22 17:45:47 by yumamur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#include "./parse_util.h"
#include "../util/util.h"
#include "../objects/objects.h"

_Bool			is_camera(char *str);
_Bool			is_light(char *str);
_Bool			is_object(char *str);

t_camera		*parse_camera(char **tab);
t_light_base	*parse_light(char **tab);
t_obj_base		*parse_obj(char **tab);

static void	parse_line_into_scene(char *line, t_scene *scene)
{
	char	**tab;

	tab = str_to_wordtab(line);
	if (!tab)
		return ;
	if (is_camera(tab[0]))
		ft_lstadd_back(&scene->cameras, ft_lstnew(parse_camera(tab)));
	else if (is_light(tab[0]))
		ft_lstadd_back(&scene->lights, ft_lstnew(parse_light(tab)));
	else if (is_object(tab[0]))
		ft_lstadd_back(&scene->objects, ft_lstnew(parse_obj(tab)));
	arr_free(tab);
}

t_scene	parse(char *filename)
{
	int		fd;
	char	*line;
	t_scene	scene;

	scene = (t_scene){0};
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return ((t_scene){0});
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		if (ft_strlen(line) >= 10)
			parse_line_into_scene(line, &scene);
		free(line);
	}
	close(fd);
	return (scene);
}
/*
C	-50,0,20		0,0,0		70

A								0.2				255,255,255
L	-40,0,30					0.7				255,255,255
sl	0,0,0			0,0,1.0		0.5		70.6	255,255,255	1.0

pl	0,0,0			0,1.0,0						255,0,225
sp	0,0,20						20				255,0,0		0.5
cy	50.0,0.0,20.6	0,0,1.0		14.2	21.42	10,0,255
cn	50.0,0.0,20.6	0,0,1.0		14.2	21.42	10,0,255

	position		normal		rad		height	rgb			reflective
*/
