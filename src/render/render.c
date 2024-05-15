/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yumamur <yumamur@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 06:21:59 by mugurel           #+#    #+#             */
/*   Updated: 2024/04/15 02:28:32 by yumamur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./t_render.h"
#include "mlx.h"
#include "libft.h"
#include "../util/fake_globals.h"
#include "../objects/objects.h"
#include "../mlx_utils/mlx_utils.h"

#include <stdio.h>

//unsigned int    pixelshader(t_scene *scene, int x, int y)
//{

//}

t_vf3	g_cam = 0;
t_vf3	g_aqua = 0;
t_vf3	g_white = 1.0;

void	set_gcam(void)
{
	// t_camera	cam;

	// cam = *(t_camera *)scene_location()->cameras->content;
	// g_cam = cam.position;
}

int	color_vf_int(t_vf3 clr, int o)
{
	int	r;
	int	g;
	int	b;

	r = (int)(clr.r * 255.0f);
	g = (int)(clr.g * 255.0f);
	b = (int)(clr.b * 255.0f);
	printf("%d \n", (int) (clr[0] * 255.0f));
	return (o << 24 | r << 16 | g << 8 | b);
}

t_ray	create_ray(int x, int y)
{
	static t_vf3	up_left = (t_vf3){-2.0f, 1.0f, -1.0f};
	static t_vf3	horizontal = (t_vf3){4.0f, 0, 0};
	static t_vf3	vertical = (t_vf3){0, 2.0f, 0};

	float u = x / WIDTH;
	float v = y / HEIGHT;

	return ((t_ray){.origin = g_cam, .direction = up_left + u * horizontal + v * verticalr});
}

void	color(t_mlx_data *mlx, int x, int y, t_ray ray)
{
	t_vf3	unit;
	float	t;

	unit = vf3_norm(ray.direction);
	t = .5 * (unit.y + 1.0);
	unsigned int clr = color_vf_int(vf3_lerp(g_white, g_aqua, t), 255);
	mlx_pixel_put(mlx->mlx, mlx->win, x, y, clr);
}


int	render(void)
{
	int			x;
	int			y;
	t_mlx_data	*data;

	set_gcam();
	data = mlx_data_location();
	y = 0;
	while (y++ < HEIGHT)
	{
		x = 0;
		while (x++ < WIDTH)
			color(data, x, y, create_ray(x, y));
	}
	return (0);
}
