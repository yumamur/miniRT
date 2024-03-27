/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yumamur <yumamur@student.42.tr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 21:48:14 by yumamur           #+#    #+#             */
/*   Updated: 2022/12/17 01:57:59 by yumamur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char	arr[14];

	if (!n)
		return (ft_putstr_fd("0", fd));
	if (n == -2147483648)
		return (ft_putstr_fd("-2147483648", fd));
	arr[13] = 0;
	if (n < 0 && ++arr[13])
		n *= -1;
	arr[12] = 0;
	while (n)
	{
		arr[10 - arr[12]++] = 48 + (n % 10);
		n /= 10;
	}
	if (arr[13])
		arr[10 - arr[12]++] = '-';
	arr[11] = 0;
	ft_putstr_fd(arr + 11 - arr[12], fd);
}
