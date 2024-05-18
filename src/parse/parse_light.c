/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_light.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yumamur <yumamur@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 21:02:49 by yumamur           #+#    #+#             */
/*   Updated: 2024/05/15 18:27:07 by yumamur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./parse.h"
#include "./tokens.h"
#include "./parse_util.h"
#include "../util/util.h"
#include "../objects/objects.h"

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

void	*parse_ambient_light(char **tab)
{
	float	ratio;
	t_vf3	color;

	if (!tab || arr_len(tab) != 3)
		return (NULL);
	if (valid_normal_atof(tab[1], &ratio)
		&& valid_ato_rgb(tab[2], &color))
		return (new_ambient_light(ratio, color));
	return (NULL);
}

void	*parse_point_light(char **tab)
{
	t_vf3	position;
	float	intensity;
	t_vf3	color;

	if (!tab || arr_len(tab) != 4)
		return (NULL);
	if (valid_ato_vf3(tab[1], &position)
		&& valid_normal_atof(tab[2], &intensity)
		&& valid_ato_rgb(tab[3], &color))
		return (new_point_light(position, intensity, color));
	return (NULL);
}

// TODO: boyle kod mu olur
void	*parse_spot_light(char **tab)
{
	t_vf3	position;
	t_vf3	direction;
	float	intensity;
	float	angle;
	t_vf3	color;

	if (!tab || arr_len(tab) != 6)
		return (NULL);
	if (valid_ato_vf3(tab[1], &position)
		&& valid_normal_ato_vf3(tab[2], &direction)
		&& valid_normal_atof(tab[3], &intensity)
		&& valid_normal_atof(tab[4], &angle)
		&& valid_ato_rgb(tab[5], &color))
		return (new_spot_light(position, direction,
				(t_vf2){intensity, angle}, color));
	return (NULL);
}

void	*parse_light(char **tab)
{
	enum e_light_type	type;

	type = get_light_type(tab[0]);
	if (type == AMBIENT_LIGHT)
		return (parse_ambient_light(tab));
	else if (type == POINT_LIGHT)
		return (parse_point_light(tab));
	else if (type == SPOT_LIGHT)
		return (parse_spot_light(tab));
	return (NULL);
}
