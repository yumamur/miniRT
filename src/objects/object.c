/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yumamur <yumamur@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 23:34:39 by yumamur           #+#    #+#             */
/*   Updated: 2024/05/22 18:26:55 by yumamur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "objects.h"
#include "../vector/vector.h"
#include "libft.h"

t_obj_base	*new_sphere(float radius, t_obj_base base)
{
	t_sphere	*sphere;

	sphere = ft_calloc(sizeof(t_sphere), 1);
	if (!sphere)
		return (NULL);
	sphere->radius = radius;
	sphere->base = base;
	sphere->base.type = SPHERE;
	sphere->base.obj = sphere;
	return (&sphere->base);
}

t_obj_base	*new_plane(t_obj_base base)
{
	t_plane	*plane;

	plane = ft_calloc(sizeof(t_plane), 1);
	if (!plane)
		return (NULL);
	plane->rotation = vf3_norm(base.rotation);
	*plane = *(t_plane *)&base;
	plane->type = PLANE;
	plane->obj = plane;
	return (plane);
}

t_obj_base	*new_triangle(t_vf3 v0, t_vf3 v1, t_vf3 v2, t_obj_base base)
{
	t_triangle	*triangle;

	triangle = ft_calloc(sizeof(t_triangle), 1);
	if (!triangle)
		return (NULL);
	base.rotation = vf3_cross(v1 - v0, v2 - v0);
	triangle->v0 = v0;
	triangle->v1 = v1;
	triangle->v2 = v2;
	triangle->base = base;
	triangle->base.type = TRIANGLE;
	triangle->base.obj = triangle;
	return (&triangle->base);
}

t_obj_base	*new_cylinder(float radius, float height, t_obj_base base)
{
	t_cylinder	*cylinder;

	cylinder = ft_calloc(sizeof(t_cylinder), 1);
	if (!cylinder)
		return (NULL);
	base.rotation = vf3_norm(base.rotation);
	cylinder->radius = radius;
	cylinder->height = height;
	cylinder->base = base;
	cylinder->top = base.position + base.rotation * (height) / 2;
	cylinder->bottom = base.position - base.rotation * (height) / 2;
	cylinder->base.type = CYLINDER;
	cylinder->base.obj = cylinder;
	return (&cylinder->base);
}

t_obj_base	*new_cone(float radius, float height, t_obj_base base)
{
	t_cone	*cone;

	cone = ft_calloc(sizeof(t_cone), 1);
	if (!cone)
		return (NULL);
	cone->radius = radius;
	cone->height = height;
	cone->base = base;
	cone->base.type = CONE;
	cone->base.obj = cone;
	return (&cone->base);
}
