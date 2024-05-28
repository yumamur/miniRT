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

#include "./render.h"
#include "t_render.h"
#include <stdlib.h> // For rand() and srand()
#include <time.h>   // For time()
#include <stdio.h>
#include "../util/util.h"
#include "../objects/objects.h"

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


int	pixelshader(t_ray *ray)
{
	t_payload payload;
	t_payload payload2;
	t_vf3 color;
	double intensity;
	int bounces;
	t_light_base *light = scene_location()->lights->content;
	t_ambient_light *ambient = light->light; 

	bounces = 0;
	intensity = 1.0f;
	color = (t_vf3){0.0f,0.0f,0.0f};
	while (bounces < 1)
	{
		payload = trace_ray(ray);
		if (payload.hit_distance == FLT_MAX)
		{
			color += light->color/255 * ambient->ratio;
			break;
		}
		t_ray ray2 = *ray;
		ray->origin = payload.origin + payload.direction * 0.0001f;
		ray->direction = vf3_norm(((t_point_light*)get_directional_light()->light)->position - payload.origin);
		payload2 = trace_ray(ray);
		if (payload2.hit_distance == FLT_MAX || payload2.hit_distance > vf3_len(((t_point_light*)get_directional_light()->light)->position - payload.origin))
		{
			double d = vf3_dot(payload.direction, ray->direction);
			color += payload.color * intensity * d;
			break;
		}
		ray->origin = payload.origin + payload.direction * 0.0001f;
		ray->direction = vf3_reflect(ray2.direction, payload.direction);
		bounces++;
	}
	return (color_vf_int(vf3_clamp(color, 0.0f, 1.0f), 255));
}

t_payload	trace_ray(t_ray *ray)
{
	t_scene *scene = scene_location();	
	t_list *temp = scene->objects;
	t_payload payload;
	t_payload closes_hit_so_far;

	closes_hit_so_far.hit_distance = FLT_MAX;
	while (scene->objects != NULL)
	{
		t_obj_base *obj = scene->objects->content;
		if(obj->type == SPHERE)
			payload = sphere_intercetion(ray, obj);
		else if(obj->type == PLANE)
		{
			if(vf3_dot(obj->rotation, ray->direction) > 0.0f)
			{
				obj->rotation = -obj->rotation;
			}
			payload = plane_intercetion(ray, obj);
		}
		else if(obj->type == CYLINDER)
			payload = plane_intercetion(ray, obj);
		if(payload.hit_distance > 0 && payload.hit_distance < closes_hit_so_far.hit_distance)	
			closes_hit_so_far = payload;
		scene->objects = scene->objects->next;
	}
	scene->objects = temp;
	return (closes_hit_so_far);
}

t_payload	sphere_intercetion(t_ray *ray, t_obj_base *obj)
{
	double	a;
	double	b;
	double	c;
	double	discriminant;
	t_payload payload;
	t_sphere *sphere;

	sphere = (t_sphere*)obj->obj;
	a = vf3_dot(ray->direction, ray->direction);
	b = 2.0f * vf3_dot(ray->origin - obj->position, ray->direction);
	c = vf3_dot(ray->origin - obj->position, ray->origin - obj->position) - sphere->radius * sphere->radius;
	discriminant = b * b - 4.0f * a * c;
	if (discriminant < 0.0f)
	{
		payload.hit_distance = FLT_MAX;
		payload.color = (t_vf3){0.0f, 0.0f, 0.0f};
		return (payload);
	}
	payload.hit_distance = (-b - sqrt(discriminant)) / (2.0f * a);
	if (payload.hit_distance < 0.0f)
	{
		payload.hit_distance = (-b + sqrt(discriminant)) / (2.0f * a);
		payload.origin = (ray->origin - obj->position) + ray->direction * payload.hit_distance;
		payload.direction = -vf3_norm(payload.origin);
		payload.origin += obj->position;
	}
	else
	{
		payload.origin = ray->origin + ray->direction * payload.hit_distance;
		payload.direction = vf3_norm(payload.origin - obj->position);
	}
	payload.color = obj->color/255;
	payload.type = obj->type;
	return (payload);
}

t_payload	plane_intercetion(t_ray *ray, t_obj_base *obj)
{
	t_payload payload;

	if (vf3_dot(obj->rotation , ray->direction) != 0.0)
	{
		payload.hit_distance = -vf3_dot(ray->origin - obj->position, obj->rotation) / vf3_dot(obj->rotation, ray->direction);
		if (payload.hit_distance > 0.0)
		{
			payload.direction = obj->rotation;
			payload.origin = ray->origin + ray->direction * payload.hit_distance;
			payload.color = obj->color/255;
			payload.type = obj->type;
			return (payload);
		}
	}
	payload.hit_distance = FLT_MAX;
	payload.color = (t_vf3){0.0f, 0.0f, 0.0f};
	return (payload);
}

void rays_init(t_ray *rays)
{
	int		x;
	int		y;
	t_vf2	d;
	double	offset;
	
	y = -1;
    while (++y < HEIGHT)
    {
		x = -1;
        while (++x < WIDTH)
        {
            offset = 0.01f * mock_rand_range(-0.5, 0.5);
            d.x = (((double)x + offset) / WIDTH - 0.5f) * (double)WIDTH / HEIGHT;
            d.y = (((double)y + offset) / HEIGHT - 0.5f);
            
            rays[x + y * WIDTH] = (t_ray){
                .origin = get_camera(0)->position +
					(t_vf3){offset, offset, 0.0f},
                .direction = (t_vf3){(d.x + get_camera(0)->look_at.x) * (get_camera(0)->fov/90), (-d.y + get_camera(0)->look_at.y) * (get_camera(0)->fov/90), get_camera(0)->look_at.z}};
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

