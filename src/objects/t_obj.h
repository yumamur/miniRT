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

typedef struct s_obj
{
	enum e_obj_type	type;
	t_vf3			position;
	t_vf3			rotation;
	t_vf3			color;
	float			reflective;
	_Bool			checkered;
	void			*data;
}	t_obj;

typedef t_obj	t_plane;

typedef struct s_triangle
{
	t_vf3	v0;
	t_vf3	v1;
	t_vf3	v2;
}	t_triangle;

typedef struct s_sphere
{
	float	radius;
}	t_sphere;

typedef struct s_cylinder
{
	float	height;
	float	radius;
}	t_cylinder;

typedef struct s_cone
{
	float	height;
	float	top_radius;
	float	bottom_radius;
}	t_cone;

#endif