#include "objects.h"
#include "libft.h"

static _Bool	is_cameras_valid(t_list *cameras)
{
	t_list	*current;

	current = cameras;
	while (current)
	{
		if (!current->content)
			return (0);
		current = current->next;
	}
	return (1);
}

static _Bool	is_lights_valid(t_list *lights)
{
	t_list	*current;

	current = lights;
	while (current)
	{
		if (!current->content)
			return (0);
		current = current->next;
	}
	return (1);
}

static _Bool	is_objects_valid(t_list *objects)
{
	t_list	*current;

	current = objects;
	while (current)
	{
		if (!current->content)
			return (0);
		current = current->next;
	}
	return (1);
}

_Bool	is_scene_valid(t_scene *scene)
{
	if (!scene)
		return (0);
	if (!scene->cameras || !scene->lights || !scene->objects)
		return (0);
	if (!is_cameras_valid(scene->cameras)
		|| !is_lights_valid(scene->lights)
		|| !is_objects_valid(scene->objects))
		return (0);
	return (1);
}