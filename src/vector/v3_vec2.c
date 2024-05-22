/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v3_vec2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yumamur <yumamur@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 07:14:36 by yumamur           #+#    #+#             */
/*   Updated: 2024/05/19 22:29:49 by yumamur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"
#include <math.h>

t_vf3	vf3_clamp(t_vf3 v, float min, float max)
{
	t_vf3	clamped;

	clamped.x = fminf(fmaxf(v.x, min), max);
	clamped.y = fminf(fmaxf(v.y, min), max);
	clamped.z = fminf(fmaxf(v.z, min), max);
	return (clamped);
}
