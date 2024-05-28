/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_object.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yumamur <yumamur@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 15:49:52 by yumamur           #+#    #+#             */
/*   Updated: 2024/05/28 15:49:52 by yumamur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "render.h"

// double	hit_sphere(t_ray *ray, t_obj_base *base)
// {
// 	t_sphere	*sp;
// 	double		ar[3];
// 	double		d;
// 	double		t1;
// 	double		t2;

// 	sp = base->obj;
// 	ar[0] = vf3_dot(ray->direction, ray->direction);
// 	ar[1] = 2.f * vf3_dot(ray->origin - base->position, ray->direction);
// 	ar[2] = vf3_dot(ray->origin - base->position, ray->origin - base->position);
// 	ar[2] -= sp->radius * sp->radius;
// 	d = ar[1] * ar[1] - 4.0f * ar[0] * ar[2];
// 	t1 = (-ar[1] - sqrt(d)) / (2.0f * ar[0]);
// 	t2 = (-ar[1] + sqrt(d)) / (2.0f * ar[0]);
//     if (t1 > 0.0 && t2 > 0.0) {
//         return (fmin(t1, t2));
//     } else if (t1 > 0.0) {
//         return (t1);
//     } else if (t2 > 0.0) {
//         return (t2);
//     } else {
// 		return (FLT_MAX);
//     }
// }

// double	fmin(double a, double b)
// {
// 	if (a > b)
// 		return (b);
// 	return (a);
// }
