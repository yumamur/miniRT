/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yumamur <yumamur@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 23:23:58 by yumamur           #+#    #+#             */
/*   Updated: 2024/05/28 20:55:13 by yumamur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "objects.h"
#include "libft.h"
#include "../vector/vector.h"
#include "../util/fake_globals.h"

t_camera	*new_camera(t_vf3 position, t_vf3 look_at, float fov)
{
	t_camera	*cam;

	cam = ft_calloc(sizeof(t_camera), 1);
	if (!cam)
		return (NULL);
	cam->position = position;
	cam->look_at = vf3_norm(look_at);
	cam->fov = fov;
	return (cam);
}

t_camera	*get_camera(int i)
{
	t_list	*ptr;

	ptr = scene_location()->cameras;
	while (ptr && i--)
		ptr = ptr->next;
	return (ptr->content);
}
