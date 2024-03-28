#include "../objects/t_core.h"
#include "../util/util.h"
#include "./parse_util.h"

t_camera	parse_camera(char **tab)
{
	t_camera	cam;

	cam = (t_camera){};
	if (!tab || arr_len(tab) != 4)
		return (cam);
	if (vf3_from_str(tab[1], &cam.position)
		&& normal_vf3_from_str(tab[2], &cam.orientation)
		&& float_from_str(tab[3], &cam.fov))
		return (cam);
	return ((t_camera){});
}