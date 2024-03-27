/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yumamur <yumamur@student.42.tr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 23:57:37 by yumamur           #+#    #+#             */
/*   Updated: 2022/12/20 21:55:00 by yumamur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	x;

	if (!dest && !src)
		return (NULL);
	if (src < dest)
	{
		while (n--)
			*(unsigned char *)(dest + n) = *(unsigned char *)(src + n);
	}
	else
	{
		x = n;
		while (n--)
		{
			*(unsigned char *)(dest) = *(unsigned char *)(src);
			++dest;
			++src;
		}
		return (dest - x);
	}
	return (dest);
}
