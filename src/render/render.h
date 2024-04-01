/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mugurel <mugurel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 06:23:03 by mugurel           #+#    #+#             */
/*   Updated: 2024/03/30 06:56:06 by mugurel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_H
# define RENDER_H

# include "../mlx_utils/mlx_utils.h"
# include "../objects/t_core.h"
# include "../libft/libft.h"
# include "../objects/t_light.h"
# include "../objects/t_obj.h"
# include <stdio.h>


void	render(t_scene *scene, t_mlx_data *mlx_data);

#endif