#ifndef OBJECTS_H
# define OBJECTS_H

# include "t_core.h"
# include "t_obj.h"
# include "t_light.h"

// TODO: remove this
void	put_scene_data(t_scene *scene);

_Bool	is_scene_valid(t_scene *scene);
void	clean_scene(t_scene *scene);

t_camera	*new_camera(t_vf3 position, t_vf3 orientation, float fov);

#endif