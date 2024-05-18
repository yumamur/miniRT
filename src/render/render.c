/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yumamur <yumamur@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 06:21:59 by mugurel           #+#    #+#             */
/*   Updated: 2024/05/16 15:13:47 by yumamur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./t_render.h"
#include <math.h>
#include <stdint.h>
#include "mlx.h"
#include "libft.h"
#include "../util/fake_globals.h"
#include "../objects/objects.h"
#include "../mlx_utils/mlx_utils.h"

#include <stdio.h>

int	color_vf_int(t_vf3 clr, int o)
{
	int	r;
	int	g;
	int	b;

	r = (int)(clr.r * 255.0f);
	g = (int)(clr.g * 255.0f);
	b = (int)(clr.b * 255.0f);
	return (o << 24 | r << 16 | g << 8 | b);
}

// t_ray	create_ray(int x, int y)
// {
// 	static t_vf3	up_left = (t_vf3){-2.0f, 1.0f, -1.0f};
// 	static t_vf3	horizontal = (t_vf3){4.0f, 0, 0};
// 	static t_vf3	vertical = (t_vf3){0, 2.0f, 0};

// 	float u = x / WIDTH;
// 	float v = y / HEIGHT;

// 	return ((t_ray){.origin = g_cam, .direction = up_left + u * horizontal + v * vertical});
// }

// void	color(t_mlx_data *mlx, int x, int y, t_ray ray)
// {
// 	t_vf3	unit;
// 	float	t;

// 	unit = vf3_norm(ray.direction);
// 	t = .5 * (unit.y + 1.0);
// 	unsigned int clr = color_vf_int(vf3_lerp(g_white, g_aqua, t), 255);
// 	mlx_pixel_put(mlx->mlx, mlx->win, x, y, clr);
// }

int	pixelshader(t_ray *ray)
{
	float	a;
	float	b;
	float	c;
	float	radius = 0.6f;
	float	discriminant;

	a = vf3_dot(ray->direction, ray->direction);
	b = 2.0f * vf3_dot(ray->origin, ray->direction);
	c = vf3_dot(ray->origin, ray->origin) - radius * radius;
	discriminant = b * b - 4.0f * a * c;
	if (discriminant < 0.0f)
		return (0xff000000);
	float closes = (-b - sqrt(discriminant)) / (2.0f * a);
	t_vf3 hit_point = ray->origin + ray->direction * closes;
	t_vf3 normal = vf3_norm(hit_point);
	
	t_vf3 light_direction = vf3_norm((t_vf3){1.0f, -1.0f, 1.0f});
	float d = vf3_dot(-light_direction, normal);
	if (d < 0.0f)
		d = 0.0f;
	t_vf3 light_color = (t_vf3){1.0f, 1.0f, 1.0f};
	light_color = light_color * d;
	return (color_vf_int(vf3_clamp(light_color, 0.08f, 1.0f), 255));
}

// void	rays_init(t_ray *rays)
// {
// 	float	aspect_ratio;
// 	int		x;
// 	int		y;

// 	aspect_ratio = (float)WIDTH / HEIGHT;
// 	y = 0;
// 	while (y < HEIGHT)
// 	{
// 		x = 0;
// 		while (x < WIDTH)
// 		{
// 			rays[x + y * WIDTH] = (t_ray){
// 				.origin = get_camera(0)->position,
// 				.direction = (t_vf3){
// 				(((float)x / WIDTH) - .5f) * aspect_ratio,
// 				((float)y / HEIGHT) - .5f,
// 				1.0f}};
// 			++x;
// 		}
// 		++y;
// 	}
// }
#include <stdlib.h> // For rand() and srand()
#include <time.h>   // For time()

void rays_init(t_ray *rays)
{
	int		x;
	int		y;
	t_vf2	d;
	float	offset;
	
    srand(clock());
	y = -1;
    while (++y < HEIGHT)
    {
		x = -1;
        while (++x < WIDTH)
        {
            offset = 0.02f * ((float)rand() / (float)RAND_MAX - 0.5f);

            d.x = (((float)x + offset) / WIDTH - 0.5f) * (float)WIDTH / HEIGHT;
            d.y = (((float)y + offset) / HEIGHT - 0.5f);
            
            rays[x + y * WIDTH] = (t_ray){
                .origin = get_camera(0)->position +
					(t_vf3){offset, offset, 0.0f},
                .direction = (t_vf3){d.x, d.y, 1.0f}};
        }
    }
}

int	calc_color(int prev_color, int new_color, int j)
{
	int	r;
	int	g;
	int	b;
	int	o;

	o = (prev_color >> 24) & 0xff;
	r = (((prev_color >> 16) & 0xff) * j + ((new_color >> 16) & 0xff))
		/ (j + 1);
	g = (((prev_color >> 8) & 0xff) * j + ((new_color >> 8) & 0xff)) / (j + 1);
	b = ((prev_color & 0xff) * j + (new_color & 0xff)) / (j + 1);
	return (o << 24 | r << 16 | g << 8 | b);
}
// int calc_color(uint32_t prev_color, uint32_t new_color, int j)
// {
//     float o_prev = (prev_color >> 24) & 0xff;
//     float r_prev = (prev_color >> 16) & 0xff;
//     float g_prev = (prev_color >> 8) & 0xff;
//     float b_prev = prev_color & 0xff;

//     float o_new = (new_color >> 24) & 0xff;
//     float r_new = (new_color >> 16) & 0xff;
//     float g_new = (new_color >> 8) & 0xff;
//     float b_new = new_color & 0xff;

//     float factor = .5f / (j + 1);

//     float o_interp = o_prev * factor + o_new * (1.0f - factor);
//     float r_interp = r_prev * factor + r_new * (1.0f - factor);
//     float g_interp = g_prev * factor + g_new * (1.0f - factor);
//     float b_interp = b_prev * factor + b_new * (1.0f - factor);

//     int interp_color = ((uint32_t)o_interp << 24) |
//                             ((uint32_t)r_interp << 16) |
//                             ((uint32_t)g_interp << 8) |
//                             (uint32_t)b_interp;

//     return interp_color;
// }

int	render(void)
{
	int		j;
	int		x;
	int		y;
	t_ray	*rays;

	rays = rays_location();
	j = 0;
	while (++j <= 100)
	{
		rays_init(rays);
		y = -1;
		while (++y < HEIGHT)
		{
			x = -1;
			while (++x < WIDTH)
			{
				my_mlx_pixel_put(x, y,
					calc_color(*get_pixel(x, y),
						pixelshader(&rays[x + y * WIDTH]), j));
			}
			put_current_img();
		}
	}
	put_current_img();
	return (0);
}
