/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_scene.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yumamur <yumamur@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 23:22:15 by yumamur           #+#    #+#             */
/*   Updated: 2024/04/03 23:22:15 by yumamur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "objects.h"
#include "libft.h"
#include "../util/util.h"

void	clean_scene(t_scene *scene)
{
	ft_lstclear(&scene->cameras, free_non_null);
	ft_lstclear(&scene->lights, free_non_null);
	ft_lstclear(&scene->objects, free_non_null);
}
