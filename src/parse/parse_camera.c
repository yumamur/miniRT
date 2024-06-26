/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_camera.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yumamur <yumamur@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 01:50:21 by yumamur           #+#    #+#             */
/*   Updated: 2024/05/16 00:59:27 by yumamur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "../objects/objects.h"
#include "../util/util.h"
#include "./parse_util.h"

void	*parse_camera(char **tab)
{
	t_vf3		position;
	t_vf3		look_at;
	float		fov;

	position = 0;
	look_at = 0;
	fov = 0.0;
	if (!tab || arr_len(tab) != 4)
		return (NULL);
	if (valid_ato_vf3(tab[1], &position)
		&& valid_normal_ato_vf3(tab[2], &look_at)
		&& valid_atof(tab[3], &fov))
		return (new_camera(position, look_at, fov));
	return (NULL);
}
