#ifndef T_CORE_H
# define T_CORE_H

# include "./t_obj.h"
# include "./t_light.h"

typedef struct s_camera
{
	t_vf3	position;
	t_vf3	rotation;
	t_vf3	direction;
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
	t_window	window;
	t_camera	camera;
	t_light		*lights;
	t_obj		*objects;
}	t_scene;

#endif 