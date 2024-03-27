/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yumamur <yumamur@student.42.tr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 16:57:07 by yumamur           #+#    #+#             */
/*   Updated: 2022/12/16 18:40:58 by yumamur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(ssize_t count, ssize_t size)
{
	void	*pt;

	if (count < 0 && size < 0)
		return (NULL);
	pt = malloc((size_t)count * (size_t)size);
	if (!pt)
		return (NULL);
	ft_bzero(pt, (size_t)count * (size_t)size);
	return (pt);
}
