/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yumamur <yumamur@student.42.tr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 16:58:13 by yumamur           #+#    #+#             */
/*   Updated: 2022/12/17 06:48:50 by yumamur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*dups;
	size_t	len;

	len = ft_strlen(s);
	dups = ft_calloc(len + 1, 1);
	if (!dups)
		return (NULL);
	ft_memcpy(dups, s, len);
	return (dups);
}
