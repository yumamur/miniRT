/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fake_globals.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yumamur <yumamur@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 11:36:07 by yumamur           #+#    #+#             */
/*   Updated: 2024/05/16 07:00:09 by yumamur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FAKE_GLOBALS_H
# define FAKE_GLOBALS_H

struct	s_scene;
struct	s_mlx_data;

struct s_scene		*scene_location(void);
struct s_mlx_data	*mlx_data_location(void);
struct s_ray		*rays_location(void);

#endif
