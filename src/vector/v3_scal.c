/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v3_scal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yumamur <yumamur@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 21:04:01 by yumamur           #+#    #+#             */
/*   Updated: 2024/05/16 01:48:14 by yumamur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "./t_vector.h"

float	vf3_dot(t_vf3 a, t_vf3 b)
{
	return (a.x * b.x + a.y * b.y + a.z * b.z);
}

float	vf3_len(t_vf3 a)
{
	return (sqrtf(vf3_dot(a, a)));
}
