/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mugurel <mugurel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 06:21:59 by mugurel           #+#    #+#             */
/*   Updated: 2024/03/30 06:56:42 by mugurel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

//unsigned int    pixelshader(t_scene *scene, int x, int y)
//{

//}

void render(t_scene *scene, t_mlx_data *mlx_data)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while(x < 400)
	{
		while(y < 400)
		{
			my_mlx_pixel_put(mlx_data, x, y, create_trgb(255,255,255,255));
			y++;
		}
		x++;
		y = 0;
	}

	printf("Rendering scene\n");
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
	// // ft_lstclear(scene, free);
}