/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yumamur <yumamur@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 21:02:24 by yumamur           #+#    #+#             */
/*   Updated: 2024/03/29 02:05:11 by yumamur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	float	res;
	float	dec;
	int		sign;

	res = 0;
	dec = 0;
	sign = 1;
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
		res = res * 10 + *str++ - '0';
	if (*str == '.')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		dec = dec * 10 + *str++ - '0';
		res *= 10;
	}
	return ((res + dec) * sign);
}

_Bool	in_range_f(float f, float min, float max)
{
	return (f >= min && f <= max);
}
