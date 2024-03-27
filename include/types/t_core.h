#ifndef T_CORE_H
# define T_CORE_H

# include "./t_vector.h"
# include "./t_obj.h"
# include "./t_light.h"

typedef struct s_camera
{
	t_v3	position;
	t_v3	rotation;
	t_v3	direction;
	float	fov;
}	t_camera;

typedef struct s_scene
{
	t_v3	camera;
	t_light	*lights;
	t_obj	*objects;
}	t_scene;

#endif 