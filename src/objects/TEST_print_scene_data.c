#include <stdio.h>
#include "objects.h"
#include "libft.h"

void	put_scene_data(t_scene *scene)
{
	printf("Rendering scene\n");
	int i = 0;
	printf("Cameras:\n");
	for (t_list *camera = scene->cameras; camera; camera = camera->next)
	{
		t_camera *c = camera->content;
		printf(" index: %d\n", i++);
		printf("  position: %f %f %f\n", c->position.x, c->position.y, c->position.z);
		printf("  orientation: %f %f %f\n", c->orientation.x, c->orientation.y, c->orientation.z);
		printf("  rotation: %f %f %f\n", c->rotation.x, c->rotation.y, c->rotation.z);
		printf("  fov: %f\n", c->fov);
	}
 
	i = 0;
	printf("\nLights:\n");
	for (t_list *light = scene->lights; light; light = light->next)
	{
		t_light *l = light->content;
		printf(" index: %d\n", i++);
		printf("  type: %d\n", l->type);
		printf("  position: %f %f %f\n", l->position.x, l->position.y, l->position.z);
		printf("  color: %f %f %f\n", l->color.x, l->color.y, l->color.z);
		printf("  intensity: %f\n", l->intensity);
	}
 
	i = 0;
	printf("\nObjects:\n");
	for (t_list *obj = scene->objects; obj; obj = obj->next)
	{
		t_obj_base *o = obj->content;
		printf(" index: %d\n", i++);
		printf("  type: %d\n", o->type);
		printf("  position: %f %f %f\n", o->position.x, o->position.y, o->position.z);
		printf("  rotation: %f %f %f\n", o->rotation.x, o->rotation.y, o->rotation.z);
		printf("  color: %f %f %f\n", o->color.x, o->color.y, o->color.z);
		printf("  reflectivity: %f\n", o->reflectivity);
	}
}