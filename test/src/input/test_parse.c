/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_parse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yumamur <yumamur@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 21:01:58 by yumamur           #+#    #+#             */
/*   Updated: 2024/03/29 01:09:36 by yumamur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../../../src/libft/libft.h"
#include "../../../src/objects/t_core.h"
#include "../../../src/objects/t_obj.h"
#include "../../../src/objects/t_light.h"

t_scene	*parse(char *filename);

void	display_scene_data(t_scene *scene)
{
	printf("Camera:\n");
	printf("  position: %f %f %f\n", scene->camera.position.x, scene->camera.position.y, scene->camera.position.z);
	printf("  orientation: %f %f %f\n", scene->camera.orientation.x, scene->camera.orientation.y, scene->camera.orientation.z);
	printf("  rotation: %f %f %f\n", scene->camera.rotation.x, scene->camera.rotation.y, scene->camera.rotation.z);
	printf("  fov: %f\n", scene->camera.fov);

	int i = 0;
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
	// ft_lstclear(scene, free);
}

// void	test_parse(void)
// {
// 	t_scene	*scene;

// 	scene = parse("test_file");
// 	// assert(scene->camera.fov == 0);
// 	// assert(scene->objects == NULL);
// 	// assert(scene->lights == NULL);
// }

int	main(int argc, char *argv[])
{
	(void)argc;
	display_scene_data(parse(argv[1]));
}