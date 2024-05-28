/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yumamur <yumamur@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 21:02:11 by yumamur           #+#    #+#             */
/*   Updated: 2024/05/28 08:31:01 by yumamur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"
#include "util/fake_globals.h"
#include "objects/objects.h"
#include "./parse/parse.h"
#include "./render/render.h"
#include "mlx.h"

#include <stdio.h>


int	main(int argc, char *argv[])
{
	if (!is_file_valid(argc, argv))
		return (1);
	*scene_location() = parse(argv[1]);
	if (!is_scene_valid())
	{
		printf("Scene is not valid.\n");
		clean_scene();
		return (0);
	}
	mlx_initialize();
	mlx_loop(mlx_data_location()->mlx);
	clean_scene();
	return (0);
}
