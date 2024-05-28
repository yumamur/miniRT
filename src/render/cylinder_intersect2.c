/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_intersect2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yumamur <yumamur@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 12:30:57 by yumamur           #+#    #+#             */
/*   Updated: 2024/05/28 12:30:58 by yumamur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./render.h"
#include <stdbool.h>

bool	intersect_ray_plane(t_ray *ray, t_vf3 point, t_vf3 normal, double *t)
{
	double	denom;
	t_vf3	p0l0;

	denom = vf3_dot(normal, ray->direction);
	if (fabs(denom) > 1e-6)
	{
		p0l0 = point - ray->origin;
		*t = vf3_dot(p0l0, normal) / denom;
		return (*t >= 0);
	}
	return (false);
}

bool	intersect_circle(t_ray *ray, t_cylinder *cy, t_vf3 point, double *t)
{
	t_vf3	to_center;

	if (intersect_ray_plane(ray, point, cy->base.rotation, t))
	{
		to_center = ray->origin + ray->direction * (*t) - point;
		if (vf3_dot(to_center, to_center) <= pow(cy->radius, 2))
			return (true);
	}
	return (false);
}

void	calc_top_hit(t_ray *ray, t_cylinder *cy, t_payload *payload)
{
	double		t;
	t_vf3		hit_point;
	t_vf3		to_center;

	if (intersect_circle(ray, cy, cy->top, &t))
	{
		hit_point = ray->origin + ray->direction * t;
		to_center = hit_point - cy->top;
		if (vf3_dot(to_center, to_center) <= pow(cy->radius, 2)
			&& t < payload->hit_distance)
		{
			payload->hit_distance = t;
			payload->origin = hit_point;
			payload->direction = cy->base.rotation;
			payload->color = cy->base.color * 1.0 / 255.0;
		}
	}
}

void	calc_bottom_hit(t_ray *ray, t_cylinder *cy, t_payload *payload)
{
	double		t;
	t_vf3		hit_point;
	t_vf3		to_center;

	if (intersect_circle(ray, cy, cy->bottom, &t))
	{
		hit_point = ray->origin + ray->direction * t;
		to_center = hit_point - cy->bottom;
		if (vf3_dot(to_center, to_center) <= pow(cy->radius, 2)
			&& t < payload->hit_distance)
		{
			payload->hit_distance = t;
			payload->origin = hit_point;
			payload->direction = -cy->base.rotation;
			payload->color = cy->base.color * 1.0 / 255.0;
		}
	}
}
