/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yumamur <yumamur@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 21:02:11 by yumamur           #+#    #+#             */
/*   Updated: 2024/04/11 18:12:52 by yumamur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"
#include "util/fake_globals.h"
#include "objects/objects.h"
#include "./parse/parse.h"
#include "./render/render.h"
#include "mlx.h"

#include <stdio.h>

void	mock_render(t_scene *scene, t_mlx_data *mlx_data)
{
	(void)scene;
	(void)mlx_data;
}

int	main(int argc, char *argv[])
{
	if (!is_file_valid(argc, argv))
		return (1);
	*scene_location() = parse(argv[1]);
	if (!is_scene_valid())
	{
		printf("Scene is not valid.");
		clean_scene();
		return (0);
	}
	mlx_initialize();
	// put_scene_data();
	mlx_loop(mlx_data_location()->mlx);
	clean_scene();
	return (0);
}
