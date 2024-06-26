/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arr_util.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yumamur <yumamur@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 21:03:36 by yumamur           #+#    #+#             */
/*   Updated: 2024/04/03 01:37:43 by yumamur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	arr_free(void *data)
{
	void	**arr;
	int		i;

	i = 0;
	arr = (void **)data;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

unsigned int	arr_len(void **data)
{
	size_t	i;

	if (!data || !*data)
		return (0);
	i = 0;
	while (data[i])
		i++;
	return (i);
}
