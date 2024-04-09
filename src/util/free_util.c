/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_util.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yumamur <yumamur@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 23:23:53 by yumamur           #+#    #+#             */
/*   Updated: 2024/04/03 23:23:54 by yumamur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	free_non_null(void *data)
{
	if (data)
		free(data);
}

void	free_and_null(void *data)
{
	if (data)
		free(data);
	data = NULL;
}
