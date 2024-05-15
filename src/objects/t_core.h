/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_core.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yumamur <yumamur@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 21:03:23 by yumamur           #+#    #+#             */
/*   Updated: 2024/04/10 16:13:39 by yumamur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_CORE_H
# define T_CORE_H

# include "libft.h"
# include "../vector/t_vector.h"

typedef struct s_camera
{
	t_vf3	position;
	t_vf3	rotation;
	t_vf3	orientation;
	float	fov;
}	t_camera;

typedef struct s_window
{
	int		width;
	int		height;
	float	aspect_ratio;
	void	*mlx;
	int		img_width;
	int		img_height;
	int		**img_raw;
}	t_window;

typedef struct s_scene
{
	t_window		window;
	struct s_list	*cameras;
	struct s_list	*lights;
	struct s_list	*objects;
}	t_scene;

#endif
