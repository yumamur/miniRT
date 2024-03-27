/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yumamur <yumamur@student.42.tr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 14:56:14 by yumamur           #+#    #+#             */
/*   Updated: 2022/12/25 00:01:01 by yumamur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	ssize_t	len;

	if (!s)
		return (NULL);
	len = ft_strlen(s);
	if (!c)
		return ((char *)s + len);
	else if (!*s)
		return (NULL);
	while (len--)
		if (s[len] == (char) c)
			return ((char *)s + len);
	return (NULL);
}
