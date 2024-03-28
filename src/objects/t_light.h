/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_light.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yumamur <yumamur@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 21:03:24 by yumamur           #+#    #+#             */
/*   Updated: 2024/03/28 21:03:25 by yumamur          ###   ########.fr       */
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

typedef struct s_light
{
	enum e_light_type	type;
	t_vf3				position;
	t_vf3				color;
	float				intensity;
	t_vf3				direction;
	float				penumbra;
}	t_light;

#endif
