/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TEST_print_scene_data.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yumamur <yumamur@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 23:28:51 by yumamur           #+#    #+#             */
/*   Updated: 2024/04/03 23:54:43 by yumamur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "objects.h"
#include "libft.h"

void	print_camera_datas(t_list *cs)
{
	int			i;
	t_camera	*c;

	i = 0;
	while (cs)
	{
		c = (t_camera *)cs->content;
		printf(" index: %d\n", i++);
		printf("  position: %f %f %f\n",
			c->position.x,
			c->position.y,
			c->position.z);
		printf("  orientation: %f %f %f\n",
			c->orientation.x,
			c->orientation.y,
			c->orientation.z);
		printf("  rotation: %f %f %f\n",
			c->rotation.x,
			c->rotation.y,
			c->rotation.z);
		printf("  fov: %f\n", c->fov);
		cs = cs->next;
	}
}

void	print_light_datas(t_list *ls)
{
	int				i;
	t_light_base	*l;

	i = 0;
	while (ls)
	{
		l = (t_light_base *)ls->content;
		printf(" index: %d\n", i++);
		printf("  type: %d\n", l->type);
		// printf("  position: %f %f %f\n",
		// 	l->position.x,
		// 	l->position.y,
		// 	l->position.z);
		printf("  color: %f %f %f\n", l->color.x, l->color.y, l->color.z);
		// printf("  intensity: %f\n", l->intensity);
		ls = ls->next;
	}
}

void	print_object_datas(t_list *obj)
{
	int			i;
	t_obj_base	*o;

	i = 0;
	while (obj)
	{
		o = (t_obj_base *)obj->content;
		printf(" index: %d\n", i++);
		printf("  type: %d\n", o->type);
		printf("  position: %f %f %f\n",
			o->position.x,
			o->position.y,
			o->position.z);
		printf("  rotation: %f %f %f\n",
			o->rotation.x,
			o->rotation.y,
			o->rotation.z);
		printf("  color: %f %f %f\n", o->color.x, o->color.y, o->color.z);
		printf("  reflectivity: %f\n", o->reflectivity);
		obj = obj->next;
	}
}

void	put_scene_data(t_scene *scene)
{
	printf("Rendering scene\n");
	printf("Cameras:\n");
	print_camera_datas(scene->cameras);
	printf("\nLights:\n");
	print_light_datas(scene->lights);
	printf("\nObjects:\n");
	print_object_datas(scene->objects);
}
