/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere_intersect.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yumamur <yumamur@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 13:36:37 by yumamur           #+#    #+#             */
/*   Updated: 2024/05/28 17:14:47 by yumamur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./render.h"
#include "t_render.h"
#include "../util/util.h"
#include "../objects/objects.h"

static t_vf3	disc_quad(t_ray *ray, t_obj_base *obj)
{
	double		a;
	double		b;
	double		c;
	double		discriminant;
	t_sphere	*sphere;

	sphere = (t_sphere *)obj->obj;
	a = vf3_dot(ray->direction, ray->direction);
	b = 2.0f * vf3_dot(ray->origin - obj->position, ray->direction);
	c = vf3_dot(ray->origin - obj->position, ray->origin - obj->position)
		- sphere->radius * sphere->radius;
	discriminant = b * b - 4.0f * a * c;
	return ((t_vf3){discriminant, (-b - sqrt(discriminant)) / (2.0f * a),
		(-b + sqrt(discriminant)) / (2.0f * a)});
}

static void	calc_hit(t_vf3 dq, t_ray *ray, t_obj_base *obj, t_payload *payload)
{
	payload->hit_distance = dq.y;
	if (payload->hit_distance < 0.0f)
	{
		payload->hit_distance = dq.z;
		payload->origin = (ray->origin - obj->position)
			+ ray->direction * payload->hit_distance;
		payload->direction = -vf3_norm(payload->origin);
		payload->origin += obj->position;
	}
	else
	{
		payload->origin = ray->origin + ray->direction * payload->hit_distance;
		payload->direction = vf3_norm(payload->origin - obj->position);
	}
	payload->color = obj->color / 255;
	payload->type = obj->type;
}

t_payload	sphere_intercetion(t_ray *ray, t_obj_base *obj)
{
	t_vf3		dq;
	t_payload	payload;

	dq = disc_quad(ray, obj);
	if (dq.x < 0.0f)
	{
		payload.hit_distance = FLT_MAX;
		payload.color = (t_vf3){0.0f, 0.0f, 0.0f};
		return (payload);
	}
	calc_hit(dq, ray, obj, &payload);
	return (payload);
}
