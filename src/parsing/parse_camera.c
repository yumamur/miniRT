/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_camera.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yumamur <yumamur@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 01:50:21 by yumamur           #+#    #+#             */
/*   Updated: 2024/03/29 01:50:25 by yumamur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../objects/t_core.h"
#include "../util/util.h"
#include "./parse_util.h"

t_camera	parse_camera(char **tab)
{
	t_camera	cam;

	cam = (t_camera){};
	if (!tab || arr_len(tab) != 4)
		return (cam);
	if (vf3_from_str(tab[1], &cam.position)
		&& normal_vf3_from_str(tab[2], &cam.orientation)
		&& float_from_str(tab[3], &cam.fov))
		return (cam);
	return ((t_camera){});
}
