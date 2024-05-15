/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_scene_valid.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yumamur <yumamur@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 23:22:35 by yumamur           #+#    #+#             */
/*   Updated: 2024/04/11 11:52:52 by yumamur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "objects.h"
#include "libft.h"
#include "../util/fake_globals.h"

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
