/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_intersect.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yumamur <yumamur@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 08:13:23 by yumamur           #+#    #+#             */
/*   Updated: 2024/05/28 08:34:36 by yumamur          ###   ########.fr       */
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

void	calculate_caps(t_ray *ray, t_cylinder *cy, t_payload *payload)
{
	double		t;
	t_vf3		hit_point;
	t_vf3		to_center;

	if (intersect_ray_plane(ray, cy->bottom, -cy->base.rotation, &t))
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
	if (intersect_ray_plane(ray, cy->top, cy->base.rotation, &t))
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

static t_vf3	cy_discriminant(t_ray *ray, t_obj_base *obj)
{
	t_cylinder	*cylinder;
	t_vf3		oc;
	float		a;
	float		c;
	float		b;

	cylinder = obj->obj;
	oc = ray->origin - cylinder->bottom;
	a = vf3_dot(ray->direction, ray->direction)
		- pow(vf3_dot(ray->direction, obj->rotation), 2);
	b = (vf3_dot(ray->direction, oc) - vf3_dot(ray->direction, obj->rotation)
			* vf3_dot(oc, obj->rotation)) * 2;
	c = vf3_dot(oc, oc) - pow(vf3_dot(oc, obj->rotation), 2)
		- pow(cylinder->radius, 2);
	oc.x = b * b - 4 * a * c;
	oc.y = (-b - sqrt(oc.x)) / (2 * a);
	oc.z = (-b + sqrt(oc.x)) / (2 * a);
	return (oc);
}

void	calc_hit_p(t_ray *ray, t_cylinder *cy, double t, t_payload *payload)
{
	t_vf3		hit_point;
	double		hit_z;

	hit_point = ray->origin + ray->direction * t;
	hit_z = vf3_dot(hit_point - cy->bottom, cy->base.rotation);
	if (hit_z >= 0 && hit_z <= cy->height)
	{
		payload->hit_distance = t;
		payload->origin = hit_point;
		payload->direction = vf3_norm(hit_point);
		payload->color = cy->base.color * 1.0 / 255.0;
	}
}

double	get_t(double t1, double t2)
{
	double	t;

	if (t1 < t2)
		t = t1;
	else
		t = t2;
	if (t < 0)
	{
		if (t1 < 0)
			t = t2;
		else if (t2 < 0)
			t = t1;
		else
			t = -1;
	}
	return (t);
}

t_payload	cylinder_intersection(t_ray *ray, t_obj_base *obj)
{
	t_cylinder	*cy;
	t_vf3		dsc_quad;
	t_payload	payload;
	double		t;

	cy = obj->obj;
	dsc_quad = cy_discriminant(ray, obj);
	payload.hit_distance = FLT_MAX;
	payload.color = (t_vf3){0.0f, 0.0f, 0.0f};
	if (dsc_quad.x >= 0)
	{
		t = get_t(dsc_quad.y, dsc_quad.z);
		if (t >= 0)
			calc_hit_p(ray, cy, t, &payload);
	}
	calculate_caps(ray, cy, &payload);
	return (payload);
}
