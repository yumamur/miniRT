/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fake_globals.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yumamur <yumamur@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 11:36:07 by yumamur           #+#    #+#             */
/*   Updated: 2024/04/11 11:51:18 by yumamur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FAKE_GLOBALS_H
# define FAKE_GLOBALS_H

struct	s_scene;
struct	s_mlx_data;

struct s_scene		*scene_location(void);
struct s_mlx_data	*mlx_data_location(void);

#endif
