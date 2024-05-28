/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_util_num.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yumamur <yumamur@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 21:02:56 by yumamur           #+#    #+#             */
/*   Updated: 2024/05/28 04:07:57 by yumamur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "../vector/t_vector.h"
#include "../util/util.h"

_Bool	is_int(char *str);
_Bool	is_float(char *str);
float	ft_atof(char *str);
_Bool	in_range_f(float f, float min, float max);

_Bool	valid_atof(char *str, float *addr)
{
	if (!str || (!is_float(str) && !is_int(str)))
		return (0);
	*addr = ft_atof(str);
	return (1);
}

_Bool	valid_normal_atof(char *str, float *addr)
{
	if (!valid_atof(str, addr))
		return (0);
	if (!in_range_f(*addr, 0, 1))
		return (0);
	return (1);
}

_Bool	valid_ato_vf3(char *str, t_vf3 *addr)
{
	char	**tab;
	char	*pt;

	pt = ft_strchr(str, ',');
	if (!pt || !ft_strchr(pt + 1, ','))
		return (0);
	pt = ft_strchr(pt + 1, ',');
	if (ft_strchr(pt + 1, ','))
		return (0);
	tab = ft_split(str, ',');
	if (!tab || !tab[0] || (!is_float(tab[0]) && !is_int(tab[0]))
		|| !tab[1] || (!is_float(tab[1]) && !is_int(tab[1]))
		|| !tab[2] || (!is_float(tab[2]) && !is_int(tab[2])))
		return (0);
	*addr = (t_vf3){ft_atof(tab[0]), ft_atof(tab[1]), ft_atof(tab[2])};
	arr_free(tab);
	return (1);
}

_Bool	valid_ato_rgb(char *str, t_vf3 *addr)
{
	_Bool	ret;

	ret = valid_ato_vf3(str, addr);
	if (ret && !in_range_f(addr->x, 0, 255)
		&& !in_range_f(addr->y, 0, 255)
		&& !in_range_f(addr->z, 0, 255))
		return (0);
	return (ret);
}

_Bool	valid_normal_ato_vf3(char *str, t_vf3 *addr)
{
	_Bool	ret;

	ret = valid_ato_vf3(str, addr);
	if (ret && !in_range_f(addr->x, -1, 1)
		&& !in_range_f(addr->y, -1, 1)
		&& !in_range_f(addr->z, -1, 1))
		return (0);
	return (ret);
}
