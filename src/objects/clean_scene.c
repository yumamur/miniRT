#include "objects.h"
#include "libft.h"
#include "../util/util.h"

void	clean_scene(t_scene *scene)
{
	ft_lstclear(&scene->cameras, free_non_null);
	ft_lstclear(&scene->lights, free_non_null);
	ft_lstclear(&scene->objects, free_non_null);
}