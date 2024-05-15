/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yumamur <yumamur@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 23:23:58 by yumamur           #+#    #+#             */
/*   Updated: 2024/04/03 23:23:59 by yumamur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "objects.h"
#include "libft.h"

t_camera	*new_camera(t_vf3 position, t_vf3 orientation, float fov)
{
	t_camera	*cam;

	cam = ft_calloc(sizeof(t_camera), 1);
	if (!cam)
		return (NULL);
	cam->position = position;
	cam->orientation = orientation;
	cam->fov = fov;
	cam->rotation = (t_vf3){0, 0, 0};
	return (cam);
}
