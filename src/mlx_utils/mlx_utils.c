/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yumamur <yumamur@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 04:26:46 by mugurel           #+#    #+#             */
/*   Updated: 2024/04/11 14:10:25 by yumamur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./mlx_utils.h"
#include "../render/render.h"
#include "mlx.h"
#include "../util/fake_globals.h"
#include <endian.h>

#include <stdlib.h>
#include <stdio.h>

int	handle_exit(void *param)
{
	(void)param;
	exit(0);
}

int	handle_key(int key, void *param)
{
	(void)param;
	printf("%d\n", key);
	if (key == 65307)
		exit(0);
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

void	my_mlx_pixel_put(int x, int y, int color)
{
	t_mlx_data	*data;
	char		*dst;

	data = mlx_data_location();
	dst = data->addr
		+ (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

#if BYTE_ORDER == LITTLE_ENDIAN

int	create_trgb(int r, int g, int b, int o)
{
	return (o << 24 | r << 16 | g << 8 | b);
}

#elif BYTE_ORDER == BIG_ENDIAN

int	create_trgb(int r, int g, int b, int o)
{
	return (o << 24 | b << 16 | g << 8 | r);
}

#endif
