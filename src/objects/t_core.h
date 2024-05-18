/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_core.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yumamur <yumamur@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 21:03:23 by yumamur           #+#    #+#             */
/*   Updated: 2024/05/16 01:20:34 by yumamur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_CORE_H
# define T_CORE_H

# include "libft.h"
# include "../vector/t_vector.h"

typedef struct s_camera
{
	t_vf3	position;
	t_vf3	look_at;
	float	fov;
}	t_camera;

typedef struct s_scene
{
	struct s_list	*cameras;
	struct s_list	*lights;
	struct s_list	*objects;
}	t_scene;

#endif
