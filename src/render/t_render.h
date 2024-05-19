/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_render.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yumamur <yumamur@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 17:17:23 by yumamur           #+#    #+#             */
/*   Updated: 2024/04/11 17:19:01 by yumamur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_RENDER_H
# define T_RENDER_H

# include "../vector/vector.h"
# include <stdint.h>

typedef struct s_ray
{
	t_vf3	origin;
	t_vf3	direction;
}	t_ray;

typedef struct s_payload
{
	t_vf3	origin;
	t_vf3	direction;
	float hit_distance;
	t_vf3 color;
}	t_payload;

#endif
