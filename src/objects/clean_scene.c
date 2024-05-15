/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_scene.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yumamur <yumamur@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 23:22:15 by yumamur           #+#    #+#             */
/*   Updated: 2024/04/11 11:49:29 by yumamur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "objects.h"
#include "libft.h"
#include "../util/util.h"
#include "../util/fake_globals.h"

void	clean_scene(void)
{
	t_scene	*scene;

	scene = scene_location();
	ft_lstclear(&scene->cameras, free_non_null);
	ft_lstclear(&scene->lights, free_non_null);
	ft_lstclear(&scene->objects, free_non_null);
}
