/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yumamur <yumamur@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 23:21:13 by yumamur           #+#    #+#             */
/*   Updated: 2024/04/03 23:57:19 by yumamur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./objects.h"
#include "libft.h"

t_light_base	*new_ambient_light(float ratio, t_vf3 color)
{
	t_ambient_light	*ambient;

	ambient = ft_calloc(sizeof(t_ambient_light), 1);
	if (!ambient)
		return (NULL);
	ambient->ratio = ratio;
	ambient->base.color = color;
	ambient->base.type = AMBIENT_LIGHT;
	ambient->base.light = (t_light_base *)ambient;
	return (&ambient->base);
}

t_light_base	*new_point_light(
	t_vf3 position,
	float intensity,
	t_vf3 color)
{
	t_point_light	*point;

	point = ft_calloc(sizeof(t_point_light), 1);
	if (!point)
		return (NULL);
	point->position = position;
	point->intensity = intensity;
	point->base.color = color;
	point->base.type = POINT_LIGHT;
	point->base.light = (t_light_base *)point;
	return (&point->base);
}

t_light_base	*new_spot_light(
	t_vf3 position,
	t_vf3 direction,
	t_vf2 xint_yangle,
	t_vf3 color)
{
	t_spot_light	*spot;

	spot = ft_calloc(sizeof(t_spot_light), 1);
	if (!spot)
		return (NULL);
	spot->position = position;
	spot->direction = direction;
	spot->intensity = xint_yangle.x;
	spot->angle = xint_yangle.y;
	spot->base.color = color;
	spot->base.type = SPOT_LIGHT;
	spot->base.light = (t_light_base *)spot;
	return (&spot->base);
}
