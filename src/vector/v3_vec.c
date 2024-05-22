/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v3_vec.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yumamur <yumamur@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 21:04:02 by yumamur           #+#    #+#             */
/*   Updated: 2024/05/18 20:44:09 by yumamur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"
#include <math.h>

extern float	vf3_dot(t_vf3 a, t_vf3 b);

t_vf3	vf3_norm(t_vf3 v)
{
	float	sq;

	sq = vf3_dot(v, v);
	if (fabs(sq) < 1e-12)
		return (v);
	return (v * (1.0 / sqrt(sq)));
}

t_vf3	vf3_proj(t_vf3 a, t_vf3 b)
{
	return (b * vf3_dot(a, b) / vf3_dot(b, b));
}

t_vf3	vf3_cross(t_vf3 a, t_vf3 b)
{
	t_vf3	c;

	c.x = a.y * b.z - a.z * b.y;
	c.y = a.z * b.x - a.x * b.z;
	c.z = a.x * b.y - a.y * b.x;
	return (c);
}

t_vf3	vf3_reflect(t_vf3 a, t_vf3 b)
{
	return (a - 2.0f * vf3_dot(a, b) * b);
}

t_vf3	vf3_lerp(t_vf3 a, t_vf3 b, float t)
{
	return (a + (b - a) * t);
}
