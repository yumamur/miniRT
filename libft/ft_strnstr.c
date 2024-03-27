/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yumamur <yumamur@student.42.tr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 17:51:13 by yumamur           #+#    #+#             */
/*   Updated: 2022/12/17 06:55:45 by yumamur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	a;

	if (!big && !len)
		return (0);
	if (!*little)
		return ((char *)big);
	while (*big && len)
	{
		a = 0;
		while (a < len && big[a] == little[a] && big[a])
		{
			if (little[a + 1] == '\0')
				return ((char *)big);
			a++;
		}
		++big;
		--len;
	}
	return (NULL);
}
