/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yumamur <yumamur@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 04:26:46 by mugurel           #+#    #+#             */
/*   Updated: 2024/05/22 22:48:54 by yumamur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./mlx_utils.h"
#include "../render/render.h"
#include "mlx.h"
#include "../util/fake_globals.h"
#include <endian.h>
#include "X11/keysymdef.h"

#include <stdlib.h>
#include <stdio.h>

void	clean_scene(void);

int	handle_exit(void *param)
{
	t_mlx_data	*data;

	(void)param;
	data = mlx_data_location();
	mlx_loop_end(data->mlx);
	mlx_expose_hook(data->win, NULL, NULL);
	mlx_destroy_image(data->mlx, data->img);
	mlx_destroy_window(data->mlx, data->win);
	clean_scene();
	return (0);
}

int	handle_key(int key, void *param)
{
	(void)param;
	if (key == XK_Escape)
		handle_exit(param);
	return (0);
}

void	mlx_initialize(void)
{
	t_mlx_data	*mlx_data;

	mlx_data = mlx_data_location();
	mlx_data->mlx = mlx_init();
	mlx_data->win = mlx_new_window(mlx_data->mlx, WIDTH, HEIGHT, "MTU");
	mlx_expose_hook(mlx_data->win, render, NULL);
	mlx_data->img = mlx_new_image(mlx_data->mlx, WIDTH, HEIGHT);
	mlx_data->addr = mlx_get_data_addr(
			mlx_data->img,
			&mlx_data->bits_per_pixel,
			&mlx_data->line_length,
			&mlx_data->endian);
	mlx_hook(mlx_data->win, 17, 0, handle_exit, NULL);
	mlx_hook(mlx_data->win, 2, 1L << 0, handle_key, NULL);
}
