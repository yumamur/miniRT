/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_scene_valid.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yumamur <yumamur@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 23:22:35 by yumamur           #+#    #+#             */
/*   Updated: 2024/05/28 21:40:53 by yumamur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "objects.h"
#include "libft.h"
#include "../util/fake_globals.h"

static _Bool	is_cameras_valid(t_list *cameras)
{
	t_list	*current;
	int		c;

	c = 0;
	current = cameras;
	while (current)
	{
		if (!current->content)
			return (0);
		c++;
		current = current->next;
	}
	if (c != 1)
		return (0);
	return (1);
}

static _Bool	is_lights_valid(t_list *lights)
{
	t_list	*current;
	int		a;
	int		p;

	a = 0;
	p = 0;
	current = lights;
	while (current)
	{
		if (!current->content)
			return (0);
		if (((t_light_base *)current->content)->type == AMBIENT_LIGHT)
			a++;
		else if (((t_light_base *)current->content)->type == POINT_LIGHT)
			p++;
		current = current->next;
	}
	if (a != 1 || p != 1)
		return (0);
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

_Bool	is_scene_valid(void)
{
	t_scene	*scene;

	scene = scene_location();
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
