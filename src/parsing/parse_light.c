/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_light.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yumamur <yumamur@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 21:02:49 by yumamur           #+#    #+#             */
/*   Updated: 2024/03/29 01:42:42 by yumamur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./tokens.h"
#include "./parse_util.h"
#include "../libft/libft.h"
#include "../util/util.h"
#include "../objects/t_light.h"

enum e_light_type	get_light_type(char *str)
{
	if (!str)
		return (-1);
	if (get_key(str) == get_key(AMBIENT_LIGHT_STR))
		return (AMBIENT_LIGHT);
	if (get_key(str) == get_key(POINT_LIGHT_STR))
		return (POINT_LIGHT);
	if (get_key(str) == get_key(SPOT_LIGHT_STR))
		return (SPOT_LIGHT);
	return (-1);
}

_Bool	parse_ambient_light(t_light *light, char **tab)
{
	if (!tab || arr_len(tab) != 3)
		return (0);
	if (normal_float_from_str(tab[1], &light->intensity)
		|| color_from_str(tab[2], &light->color))
		return (1);
	return (0);
}

_Bool	parse_point_light(t_light *light, char **tab)
{
	if (!tab || arr_len(tab) != 4)
		return (0);
	if (vf3_from_str(tab[1], &light->position)
		|| normal_float_from_str(tab[2], &light->intensity)
		|| color_from_str(tab[3], &light->color))
		return (1);
	return (0);
}

_Bool	parse_spot_light(t_light *light, char **tab)
{
	if (!tab || arr_len(tab) != 6)
		return (0);
	if (vf3_from_str(tab[1], &light->position)
		|| normal_vf3_from_str(tab[2], &light->direction)
		|| normal_float_from_str(tab[3], &light->intensity)
		|| float_from_str(tab[4], &light->penumbra)
		|| color_from_str(tab[5], &light->color))
		return (1);
	return (0);
}

t_light	*parse_light(char **tab)
{
	t_light	*light;

	light = ft_calloc(1, sizeof(t_light));
	if (!light)
		return (NULL);
	light->type = get_light_type(tab[0]);
	if ((light->type == AMBIENT_LIGHT && parse_ambient_light(light, tab))
		|| (light->type == POINT_LIGHT && parse_point_light(light, tab))
		|| (light->type == SPOT_LIGHT && parse_spot_light(light, tab)))
		return (light);
	free(light);
	return (NULL);
}