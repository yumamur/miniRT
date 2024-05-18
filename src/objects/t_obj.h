/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_obj.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yumamur <yumamur@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 21:03:27 by yumamur           #+#    #+#             */
/*   Updated: 2024/05/15 22:35:29 by yumamur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_OBJ_H
# define T_OBJ_H

# include "../vector/t_vector.h"

enum e_obj_type
{
	PLANE,
	TRIANGLE,
	SPHERE,
	CYLINDER,
	CONE,
};

typedef struct s_obj_base
{
	enum e_obj_type	type;
	t_vf3			position;
	t_vf3			rotation;
	t_vf3			color;
	float			reflectivity;
	_Bool			checkered;
	void			*obj;
}	t_obj_base;

typedef t_obj_base	t_plane;

typedef struct s_triangle
{
	t_obj_base	base;
	t_vf3		v0;
	t_vf3		v1;
	t_vf3		v2;
}	t_triangle;

typedef struct s_sphere
{
	t_obj_base	base;
	float		radius;
}	t_sphere;

typedef struct s_cylinder
{
	t_obj_base	base;
	float		height;
	float		radius;
}	t_cylinder;

typedef t_cylinder	t_cone;

#endif
