/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yumamur <yumamur@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 06:21:59 by mugurel           #+#    #+#             */
/*   Updated: 2024/04/03 23:23:28 by yumamur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "mlx.h"
#include "libft.h"
#include "../objects/objects.h"
#include "../mlx_utils/mlx_utils.h"

//unsigned int    pixelshader(t_scene *scene, int x, int y)
//{

//}

void	render(t_scene *scene, t_mlx_data *mlx_data)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (x < 400)
	{
		while (y < 400)
		{
			my_mlx_pixel_put(mlx_data, x, y, create_trgb(255, 255, 255, 255));
			y++;
		}
		x++;
		y = 0;
	}
	(void)scene;
}
