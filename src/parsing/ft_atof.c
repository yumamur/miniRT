/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yumamur <yumamur@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 21:02:24 by yumamur           #+#    #+#             */
/*   Updated: 2024/04/02 22:19:47 by yumamur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "../libft/libft.h"

_Bool	is_int(char *str)
{
	if (*str == '-')
		str++;
	while (*str >= '0' && *str <= '9')
		str++;
	return (!*str);
}

_Bool	is_float(char *str)
{
	if (*str == '-')
		str++;
	while (*str >= '0' && *str <= '9')
		str++;
	if (*str == '.')
		str++;
	while (*str >= '0' && *str <= '9')
		str++;
	return (!*str);
}

float	ft_atof(char *str)
{
	float	result;
	float	dec;
	float	c_dec;
	int		sign;

	result = 0;
	dec = 0;
	sign = 1;
	c_dec = 0;
	if (*str == '-' && str++)
		sign = -1;
	while (*str >= '0' && *str <= '9')
		result = result * 10 + *str++ - '0';
	if (*str == '.')
	{
		str++;
		while (*str >= '0' && *str <= '9' && ++c_dec)
		{
			dec = dec * 10 + *str - '0';
			str++;
		}
	}
	return (sign * (result + dec / pow(10, c_dec)));
}

_Bool	in_range_f(float f, float min, float max)
{
	return (f >= min && f <= max);
}
