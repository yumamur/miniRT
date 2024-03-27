#ifndef _T_CORE_H
# define _T_CORE_H

# include "./vector.h"
# include "./obj.h"
# include "./light.h"

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