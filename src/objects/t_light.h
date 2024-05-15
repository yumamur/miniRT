/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_light.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yumamur <yumamur@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 21:03:24 by yumamur           #+#    #+#             */
/*   Updated: 2024/04/09 18:45:19 by yumamur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_LIGHT_H
# define T_LIGHT_H

# include "../vector/t_vector.h"

enum e_light_type
{
	POINT_LIGHT,
	AMBIENT_LIGHT,
	SPOT_LIGHT
};

typedef struct s_light_base
{
	enum e_light_type	type;
	t_vf3				color;
	void				*light;
}	t_light_base;

typedef struct s_point_light
{
	t_light_base	base;
	t_vf3			position;
	float			intensity;
}	t_point_light;

typedef struct s_ambient_light
{
	t_light_base	base;
	float			ratio;
}	t_ambient_light;

typedef struct s_spot_light
{
	t_light_base	base;
	t_vf3			position;
	t_vf3			direction;
	float			intensity;
	float			angle;
}	t_spot_light;

#endif
