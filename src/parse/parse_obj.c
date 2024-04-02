/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_obj.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yumamur <yumamur@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 21:02:54 by yumamur           #+#    #+#             */
/*   Updated: 2024/04/03 01:11:50 by yumamur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "../objects/t_obj.h"
#include "../util/util.h"
#include "./parse_util.h"
#include "./tokens.h"

#include <stdlib.h>

t_obj_base	*parse_sphere(char **tab)
{
	t_sphere	*sp;

	if (!tab || arr_len(tab) != 5)
		return (NULL);
	sp = ft_calloc(1, sizeof(t_sphere));
	if (!sp)
		return (NULL);
	sp->base.type = SPHERE;
	sp->base.obj = sp;
	if (valid_ato_vf3(tab[1], &sp->base.position)
		&& valid_atof(tab[2], &sp->radius)
		&& valid_ato_rgb(tab[3], &sp->base.color)
		&& valid_normal_atof(tab[4], &sp->base.reflectivity))
		return (&sp->base);
	free(sp);
	return (NULL);
}

t_obj_base	*parse_plane(char **tab)
{
	t_plane	*pl;

	if (!tab || arr_len(tab) != 5)
		return (NULL);
	pl = ft_calloc(1, sizeof(t_plane));
	if (!pl)
		return (NULL);
	pl->type = PLANE;
	pl->obj = pl;
	if (valid_ato_vf3(tab[1], &pl->position)
		&& valid_ato_vf3(tab[2], &pl->rotation)
		&& valid_ato_rgb(tab[3], &pl->color)
		&& valid_normal_atof(tab[4], &pl->reflectivity))
		return (pl);
	free(pl);
	return (NULL);
}

t_obj_base	*parse_triangle(char **tab)
{
	t_triangle	*tr;

	if (!tab || arr_len(tab) != 7)
		return (NULL);
	tr = ft_calloc(1, sizeof(t_triangle));
	if (!tr)
		return (NULL);
	tr->base.type = TRIANGLE;
	tr->base.obj = tr;
	if (valid_ato_vf3(tab[1], &tr->v0)
		&& valid_ato_vf3(tab[2], &tr->v1)
		&& valid_ato_vf3(tab[3], &tr->v2)
		&& valid_ato_rgb(tab[4], &tr->base.color)
		&& valid_normal_atof(tab[5], &tr->base.reflectivity))
		return (&tr->base);
	free(tr);
	return (NULL);
}

t_obj_base	*parse_cylinder(char **tab, enum e_obj_type type)
{
	t_cylinder	*cy;

	if (!tab || arr_len(tab) != 7)
		return (NULL);
	cy = ft_calloc(1, sizeof(t_cylinder));
	if (!cy)
		return (NULL);
	cy->base.type = type;
	cy->base.obj = cy;
	if (valid_ato_vf3(tab[1], &cy->base.position)
		&& valid_ato_vf3(tab[2], &cy->base.rotation)
		&& valid_atof(tab[3], &cy->height)
		&& valid_atof(tab[4], &cy->radius)
		&& valid_ato_rgb(tab[5], &cy->base.color)
		&& valid_normal_atof(tab[6], &cy->base.reflectivity))
		return (&cy->base);
	free(cy);
	return (NULL);
}

void	*parse_obj(char **tab)
{
	if (get_key(tab[0]) == get_key(SPHERE_STR))
		return (parse_sphere(tab));
	else if (get_key(tab[0]) == get_key(PLANE_STR))
		return (parse_plane(tab));
	else if (get_key(tab[0]) == get_key(TRIANGLE_STR))
		return (parse_triangle(tab));
	else if (get_key(tab[0]) == get_key(CYLINDER_STR))
		return (parse_cylinder(tab, CYLINDER));
	else if (get_key(tab[0]) == get_key(CONE_STR))
		return (parse_cylinder(tab, CONE));
	return (NULL);
}
