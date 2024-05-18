/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yumamur <yumamur@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 04:26:46 by mugurel           #+#    #+#             */
/*   Updated: 2024/05/16 06:55:29 by yumamur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./mlx_utils.h"
#include "../render/render.h"
#include "mlx.h"
#include "../util/fake_globals.h"
#include <endian.h>

#include <stdlib.h>
#include <stdio.h>

void	clean_scene(void);

int	handle_exit(void *param)
{
	(void)param;
	clean_scene();
	mlx_loop_end(mlx_data_location()->mlx);
	return (0);
}

int	handle_key(int key, void *param)
{
	(void)param;
	if (key == 65307)
		handle_exit(param);
	else if (key == 53)
		render();
	return (0);
}

void	mlx_initialize(void)
{
	t_mlx_data	*mlx_data;

	mlx_data = mlx_data_location();
	mlx_data->mlx = mlx_init();
	mlx_data->win = mlx_new_window(mlx_data->mlx, WIDTH, HEIGHT, "MTU");
	mlx_data->img = mlx_new_image(mlx_data->mlx, WIDTH, HEIGHT);
	mlx_data->addr = mlx_get_data_addr(
			mlx_data->img,
			&mlx_data->bits_per_pixel,
			&mlx_data->line_length,
			&mlx_data->endian);
	mlx_hook(mlx_data->win, 17, 0, handle_exit, NULL);
	mlx_hook(mlx_data->win, 2, 1L << 0, handle_key, NULL);
}
