/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yumamur <yumamur@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 21:02:56 by yumamur           #+#    #+#             */
/*   Updated: 2024/03/29 01:29:04 by yumamur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../vector/t_vector.h"
#include "../util/util.h"

_Bool	is_float(char *str);
float	ft_atof(char *str);
_Bool	in_range_f(float f, float min, float max);

_Bool	float_from_str(char *str, float *addr)
{
	if (!str || !is_float(str))
		return (0);
	*addr = ft_atof(str);
	return (1);
}

_Bool	normal_float_from_str(char *str, float *addr)
{
	if (!float_from_str(str, addr))
		return (0);
	if (!in_range_f(*addr, 0, 1))
		return (0);
	return (1);
}

_Bool	vf3_from_str(char *str, t_vf3 *addr)
{
	char	**tab;

	tab = ft_split(str, ',');
	if (!tab || !tab[0] || !is_float(tab[0])
		|| !tab[1] || !is_float(tab[1])
		|| !tab[2] || !is_float(tab[2]))
		return (0);
	addr->x = ft_atof(tab[0]);
	addr->y =  ft_atof(tab[1]);
	addr->z = ft_atof(tab[2]);
	arr_free(tab);
	return (1);
}

_Bool	color_from_str(char *str, t_vf3 *addr)
{
	_Bool	ret;

	ret = vf3_from_str(str, addr);
	if (ret && !in_range_f(addr->x, 0, 255)
		&& !in_range_f(addr->y, 0, 255)
		&& !in_range_f(addr->z, 0, 255))
		return (0);
	return (ret);
}

_Bool	normal_vf3_from_str(char *str, t_vf3 *addr)
{
	_Bool	ret;

	ret = vf3_from_str(str, addr);
	if (ret && !in_range_f(addr->x, -1, 1)
		&& !in_range_f(addr->y, -1, 1)
		&& !in_range_f(addr->z, -1, 1))
		return (0);
	return (ret);
}
