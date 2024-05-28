/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yumamur <yumamur@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 06:21:59 by mugurel           #+#    #+#             */
/*   Updated: 2024/05/28 22:22:07 by yumamur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./render.h"
#include "t_render.h"
#include "../util/util.h"
#include "../objects/objects.h"

void	pixelshader_2(t_ray *ray, t_payload *payload, t_vf3 *color)
{
	double			d;
	t_payload		payload2;
	t_ambient_light	*ambient;
	t_point_light	*point;

	ambient = ((t_light_base *)scene_location()->lights->content)->light;
	point = (t_point_light *)get_point_light()->light;
	ray->origin = payload->origin + payload->direction * 0.0001f;
	ray->direction = vf3_norm(point->position - payload->origin);
	payload->color *= point->base.color / 255 * point->intensity;
	payload2 = trace_ray(ray);
	if (payload2.hit_distance == FLT_MAX
		|| payload2.hit_distance > vf3_len((point->position - payload->origin)))
	{
		d = vf3_dot(payload->direction, ray->direction);
		*color += ambient->base.color / 255 * ambient->ratio;
		*color += payload->color * d;
		return ;
	}
	*color += ambient->base.color / 255 * ambient->ratio;
}

int	pixelshader(t_ray *ray)
{
	t_payload		payload;
	t_vf3			color;
	t_ambient_light	*ambient;

	ambient = ((t_light_base *)scene_location()->lights->content)->light;
	color = (t_vf3){0.0f, 0.0f, 0.0f};
	payload = trace_ray(ray);
	if (payload.hit_distance == FLT_MAX)
	{
		color += ambient->base.color / 255 * ambient->ratio;
		return (color_vf_int(vf3_clamp(color, 0.0f, 1.0f), 255));
	}
	pixelshader_2(ray, &payload, &color);
	return (color_vf_int(vf3_clamp(color, 0.0f, 1.0f), 255));
}

t_payload	trace_ray(t_ray *ray)
{
	t_list		*temp;
	t_payload	load;
	t_payload	close;
	t_obj_base	*obj;

	temp = scene_location()->objects;
	close.hit_distance = FLT_MAX;
	while (temp != NULL)
	{
		obj = temp->content;
		if (obj->type == SPHERE)
			load = sphere_intercetion(ray, obj);
		else if (obj->type == PLANE)
		{
			if (vf3_dot(obj->rotation, ray->direction) > 0.0f)
				obj->rotation *= -1;
			load = plane_intercetion(ray, obj);
		}
		else if (obj->type == CYLINDER)
			load = cylinder_intersection(ray, obj);
		if (load.hit_distance > 0 && load.hit_distance < close.hit_distance)
			close = load;
		temp = temp->next;
	}
	return (close);
}

void	rays_init(t_ray *rays)
{
	int			x;
	int			y;
	t_vf2		d;
	double		off;
	t_camera	*cam;

	y = -1;
	cam = get_camera(0);
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
		{
			off = 0.01f * mock_rand_range(-0.5, 0.5);
			d.x = (((double)x + off) / WIDTH - 0.5f) * (double)WIDTH / HEIGHT;
			d.y = (((double)y + off) / HEIGHT - 0.5f);
			rays[x + y * WIDTH] = (t_ray){
				.origin = cam->position + (t_vf3){off, off, 0.0f},
				.direction = (t_vf3){
				(d.x + cam->look_at.x) * (cam->fov / 90),
				(-d.y + cam->look_at.y) * (cam->fov / 90),
				cam->look_at.z}};
		}
	}
}

int	render(void)
{
	int		j;
	int		x;
	int		y;
	t_ray	*rays;

	rays = rays_location();
	j = 0;
	while (++j <= 10)
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
