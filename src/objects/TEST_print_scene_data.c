/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TEST_print_scene_data.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yumamur <yumamur@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 23:28:51 by yumamur           #+#    #+#             */
/*   Updated: 2024/04/11 11:49:53 by yumamur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../util/fake_globals.h"
#include "libft.h"
#include "objects.h"

#include <stdio.h>

void	print_camera_datas(t_list *cs)
{
	int			i;
	t_camera	*c;

	i = 0;
	while (cs)
	{
		c = (t_camera *)cs->content;
		printf(" index: %d\n", i++);
		printf("  position: %.2f %.2f %.2f\n",
			c->position.x,
			c->position.y,
			c->position.z);
		printf("  orientation: %.2f %.2f %.2f\n",
			c->orientation.x,
			c->orientation.y,
			c->orientation.z);
		printf("  rotation: %.2f %.2f %.2f\n",
			c->rotation.x,
			c->rotation.y,
			c->rotation.z);
		printf("  fov: %.2f\n", c->fov);
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
		printf("  type: %s\n",
			l->type == AMBIENT_LIGHT
			? "Ambient"
			: l->type == SPOT_LIGHT
				? "Spot"
				: l->type == POINT_LIGHT
					? "Point"
					: "None"
		);
		printf("  color: %.2f %.2f %.2f\n", l->color.x, l->color.y, l->color.z);
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
		printf("  position: %.2f %.2f %.2f\n",
			o->position.x,
			o->position.y,
			o->position.z);
		printf("  rotation: %.2f %.2f %.2f\n",
			o->rotation.x,
			o->rotation.y,
			o->rotation.z);
		printf("  color: %.2f %.2f %.2f\n", o->color.x, o->color.y, o->color.z);
		printf("  reflectivity: %.2f\n", o->reflectivity);
		obj = obj->next;
	}
}

void	put_scene_data(void)
{
	t_scene	*scene;

	scene = scene_location();
	printf("Rendering scene\n");
	printf("Cameras:\n");
	print_camera_datas(scene->cameras);
	printf("\nLights:\n");
	print_light_datas(scene->lights);
	printf("\nObjects:\n");
	print_object_datas(scene->objects);
}
