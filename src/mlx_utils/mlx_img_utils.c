/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_img_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yumamur <yumamur@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 06:55:48 by yumamur           #+#    #+#             */
/*   Updated: 2024/05/16 07:35:45 by yumamur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_utils.h"
#include "mlx.h"
#include "../util/fake_globals.h"

void	put_current_img(void)
{
	t_mlx_data	*data;

	data = mlx_data_location();
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
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

uint32_t	*get_pixel(int x, int y)
{
	t_mlx_data	*data;
	char		*dst;

	data = mlx_data_location();
	dst = data->addr
		+ (y * data->line_length + x * (data->bits_per_pixel / 8));
	return ((uint32_t *)dst);
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
