/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_g.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yumamur <yumamur@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 21:03:38 by yumamur           #+#    #+#             */
/*   Updated: 2024/04/11 11:55:43 by yumamur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fake_globals.h"
#include "../objects/t_core.h"
#include "../mlx_utils/mlx_utils.h"

struct s_scene	*scene_location(void)
{
	static struct s_scene	g;

	return (&g);
}

struct s_mlx_data	*mlx_data_location(void)
{
	static struct s_mlx_data	g;

	return (&g);
}

void	*g2(void)
{
	static void	*g;

	return (&g);
}

void	*g3(void)
{
	static void	*g;

	return (&g);
}
