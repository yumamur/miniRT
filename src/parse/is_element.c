/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_element.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yumamur <yumamur@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 21:02:31 by yumamur           #+#    #+#             */
/*   Updated: 2024/05/22 23:21:54 by yumamur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "./tokens.h"

int	get_key(char *key)
{
	int	i;

	i = ft_strlen(key);
	if (i != 1 && i != 2)
		return (-1);
	return ((key[0] << 8) + key[1]);
}

_Bool	is_camera(char *str)
{
	return (get_key(str) == get_key(CAMERA_STR));
}

_Bool	is_light(char *str)
{
	int	key;

	key = get_key(str);
	return (key == get_key(AMBIENT_LIGHT_STR)
		|| key == get_key(POINT_LIGHT_STR)
		|| key == get_key(SPOT_LIGHT_STR));
}

_Bool	is_object(char *str)
{
	int	key;

	key = get_key(str);
	return (key == get_key(SPHERE_STR)
		|| key == get_key(PLANE_STR)
		|| key == get_key(CYLINDER_STR)
		|| key == get_key(CONE_STR));
}
