/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane_intersect.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yumamur <yumamur@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 13:36:13 by yumamur           #+#    #+#             */
/*   Updated: 2024/05/28 17:17:47 by yumamur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./render.h"
#include "t_render.h"
#include "../util/util.h"
#include "../objects/objects.h"

t_payload	plane_intercetion(t_ray *ray, t_obj_base *obj)
{
	t_payload	payload;

	if (vf3_dot(obj->rotation, ray->direction) != 0.0)
	{
		payload.hit_distance
			= -vf3_dot(ray->origin - obj->position, obj->rotation)
			/ vf3_dot(obj->rotation, ray->direction);
		if (payload.hit_distance > 0.0)
		{
			payload.direction = obj->rotation;
			payload.origin = ray->origin
				+ ray->direction * payload.hit_distance;
			payload.color = obj->color / 255;
			payload.type = obj->type;
			return (payload);
		}
	}
	payload.hit_distance = FLT_MAX;
	payload.color = (t_vf3){0.0f, 0.0f, 0.0f};
	return (payload);
}
