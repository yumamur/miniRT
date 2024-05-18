/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yumamur <yumamur@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 21:04:04 by yumamur           #+#    #+#             */
/*   Updated: 2024/05/16 07:16:50 by yumamur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H

# include "./t_vector.h"

float	v2_len(t_vf2 a);
float	v2_dot(t_vf2 a, t_vf2 b);
t_vf2	v2_norm(t_vf2 a);

float	vf3_len(t_vf3 a);
float	vf3_dot(t_vf3 a, t_vf3 b);
t_vf3	vf3_norm(t_vf3 a);
t_vf3	vf3_proj(t_vf3 a, t_vf3 b);
t_vf3	vf3_cross(t_vf3 a, t_vf3 b);
t_vf3	vf3_reflect(t_vf3 a, t_vf3 b);
t_vf3	vf3_lerp(t_vf3 a, t_vf3 b, float t);
t_vf3	vf3_clamp(t_vf3 v, float min, float max);

#endif