/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yumamur <yumamur@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 21:02:08 by yumamur           #+#    #+#             */
/*   Updated: 2024/04/02 22:19:17 by yumamur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

# include "objects/t_core.h"
# include "mlx_utils/mlx_utils.h"
# include "render/render.h"

void	handle_error(int error_code);

_Bool	is_valid(int argc, char *argv[]);
t_scene	parse(char *filename);

#endif