/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yumamur <yumamur@student.42.tr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 12:01:21 by yumamur           #+#    #+#             */
/*   Updated: 2022/12/25 00:41:25 by yumamur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char	*ret;

	*(size_t *)&ret = ft_strlen(s);
	if (start > *(size_t *)&ret)
		return (ft_strdup(""));
	s += start;
	*(size_t *)&ret = ft_strlen(s);
	if (len > *(size_t *)&ret)
		len = *(size_t *)&ret;
	ret = malloc(len + 1);
	if (!ret)
		return (NULL);
	ret[len] = 0;
	while (len--)
		ret[len] = s[len];
	return (ret);
}
