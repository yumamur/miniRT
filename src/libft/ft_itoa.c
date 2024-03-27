/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yumamur <yumamur@student.42.tr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 19:30:03 by yumamur           #+#    #+#             */
/*   Updated: 2022/12/24 23:42:11 by yumamur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h" 

char	*ft_itoa(int n)
{
	char	ret[16];

	if (n == 0)
		return (ft_strdup("0"));
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	ret[15] = 0;
	*(int *)&ret[11] = n;
	while (*(int *)&ret[11] && ++ret[15])
		*(int *)&ret[11] /= 10;
	*(int *)&ret[11] = n;
	if (n < 0 && ++ret[15])
		*(int *)&ret[11] *= -1;
	*(ret + ret[15]) = 0;
	while (ret[15]-- > 0)
	{
		*(ret + ret[15]) = 48 + (*(int *)&ret[11] % 10);
		*(int *)&ret[11] /= 10;
	}
	if (n < 0)
		ret[0] = '-';
	return (ft_strdup(ret));
}
