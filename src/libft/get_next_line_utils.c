/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yumamur <yumamur@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 16:46:07 by yumamur           #+#    #+#             */
/*   Updated: 2024/03/28 21:51:16 by yumamur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*gnl_strjoin(char *s1, char *s2)
{
	char	*str;
	int		i1;
	int		i2;

	if (!s1)
	{
		s1 = malloc(1);
		s1[0] = '\0';
	}
	if (!s1 || !s2)
		return (NULL);
	str = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!str)
		return (NULL);
	i1 = -1;
	i2 = 0;
	while (s1[++i1])
		str[i1] = s1[i1];
	while (s2[i2])
		str[i1++] = s2[i2++];
	str[i1] = '\0';
	free(s1);
	return (str);
}

int	gnl_strchr(char *str, int c)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
	{
		if (str[i] == (char )c)
			return (1);
		i++;
	}
	return (0);
}
