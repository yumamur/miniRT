/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_g.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yumamur <yumamur@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 21:03:38 by yumamur           #+#    #+#             */
/*   Updated: 2024/05/16 00:56:57 by yumamur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fake_globals.h"
#include "../render/t_render.h"
#include "../objects/t_core.h"
#include "../mlx_utils/mlx_utils.h"

t_scene	*scene_location(void)
{
	static t_scene	g;

	return (&g);
}

t_mlx_data	*mlx_data_location(void)
{
	static t_mlx_data	g;

	return (&g);
}

t_ray	*rays_location(void)
{
	static t_ray	g[WIDTH * HEIGHT];

	return (g);
}

void	*g3(void)
{
	static void	*g;

	return (&g);
}
