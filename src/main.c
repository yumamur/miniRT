/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yumamur <yumamur@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 21:02:11 by yumamur           #+#    #+#             */
/*   Updated: 2024/04/02 22:18:43 by yumamur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./main.h"
#include "objects/t_core.h"
#include "objects/t_light.h"
#include "objects/t_obj.h"
#include "libft/libft.h"
#include "../minilibx/mlx.h"
#include <stdio.h>


int	main(int argc, char *argv[])
{
	t_scene	scene;
	t_mlx_data mlx_data;

	if (!is_valid(argc, argv))
		return (1);
	mlx_initialize(&mlx_data);
	scene = parse(argv[1]);
	if (!scene.camera.fov || !scene.objects || !scene.lights)
		// TODO: free scene
		return (0);
	render(&scene, &mlx_data);
	mlx_put_image_to_window(mlx_data.mlx, mlx_data.win, mlx_data.img, 0, 0);
	mlx_loop(mlx_data.mlx);
	return (0);
}
