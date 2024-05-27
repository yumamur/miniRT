/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yumamur <yumamur@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 02:03:26 by yumamur           #+#    #+#             */
/*   Updated: 2024/05/27 18:52:17 by yumamur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_core.h"
#include "../util/fake_globals.h"
#include "objects.h"

t_ambient_light	*get_ambient_light(void)
{
	t_list	*list;

	list = scene_location()->lights;
	while (list)
	{
		if (((t_light_base *)list->content)->type == AMBIENT_LIGHT)
			return ((t_ambient_light *)list->content);
		list = list->next;
	}
	return (NULL);
}