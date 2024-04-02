/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yumamur <yumamur@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 21:02:11 by yumamur           #+#    #+#             */
/*   Updated: 2024/04/03 01:40:15 by yumamur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "objects/objects.h"
#include "./parse/parse.h"
#include "./render/render.h"

void	mock_render(t_scene *scene, t_mlx_data *mlx_data)
{
	(void)scene;
	(void)mlx_data;
}

int	main(int argc, char *argv[])
{
	t_scene	scene;
	t_mlx_data mlx_data;

	if (!is_file_valid(argc, argv))
		return (1);
	scene = parse(argv[1]);
	if (!is_scene_valid(&scene))
	{
		clean_scene(&scene);
		return (0);
	}
	mock_render(&scene, &mlx_data);
	// mlx_initialize(&mlx_data);
	// render(&scene, &mlx_data);
	put_scene_data(&scene);
	clean_scene(&scene);
	return (0);
}
