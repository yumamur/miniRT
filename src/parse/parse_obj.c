/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_obj.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yumamur <yumamur@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 21:02:54 by yumamur           #+#    #+#             */
/*   Updated: 2024/05/26 23:47:51 by yumamur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/libft/libft.h"
#include "../objects/objects.h"
#include "../util/util.h"
#include "./parse_util.h"
#include "./tokens.h"

#include <stdlib.h>

t_obj_base	*parse_sphere(char **tab)
{
	t_obj_base	base;
	float		radius;

	if (!tab || arr_len(tab) != 5)
		return (NULL);
	base = (t_obj_base){0};
	if (valid_ato_vf3(tab[1], &base.position)
		&& valid_atof(tab[2], &radius)
		&& valid_ato_rgb(tab[3], &base.color)
		&& valid_normal_atof(tab[4], &base.reflectivity))
		return (new_sphere(radius, base));
	return (NULL);
}

t_obj_base	*parse_plane(char **tab)
{
	t_obj_base	base;

	if (!tab || arr_len(tab) != 5)
		return (NULL);
	base = (t_obj_base){0};
	if (valid_ato_vf3(tab[1], &base.position)
		&& valid_ato_vf3(tab[2], &base.rotation)
		&& valid_ato_rgb(tab[3], &base.color)
		&& valid_normal_atof(tab[4], &base.reflectivity))
		return (new_plane(base));
	return (NULL);
}

t_obj_base	*parse_cylinder(char **tab, enum e_obj_type type)
{
	t_obj_base	base;
	float		height;
	float		radius;

	if (!tab || arr_len(tab) != 7)
		return (NULL);
	base = (t_obj_base){0};
	if (valid_ato_vf3(tab[1], &base.position)
		&& valid_ato_vf3(tab[2], &base.rotation)
		&& valid_atof(tab[3], &height)
		&& valid_atof(tab[4], &radius)
		&& valid_ato_rgb(tab[5], &base.color)
		&& valid_normal_atof(tab[6], &base.reflectivity))
	{
		if (type == CONE)
			return (new_cone(radius, height, base));
		return (new_cylinder(radius, height, base));
	}
	return (NULL);
}

void	*parse_obj(char **tab)
{
	if (get_key(tab[0]) == get_key(SPHERE_STR))
		return (parse_sphere(tab));
	else if (get_key(tab[0]) == get_key(PLANE_STR))
		return (parse_plane(tab));
	else if (get_key(tab[0]) == get_key(CYLINDER_STR))
		return (parse_cylinder(tab, CYLINDER));
	else if (get_key(tab[0]) == get_key(CONE_STR))
		return (parse_cylinder(tab, CONE));
	return (NULL);
}
