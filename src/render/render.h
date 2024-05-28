/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yumamur <yumamur@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 06:23:03 by mugurel           #+#    #+#             */
/*   Updated: 2024/05/28 07:51:47 by yumamur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_H
# define RENDER_H

# define FLT_MAX 3.402823466e+38F /* max value */

# include "../mlx_utils/mlx_utils.h"
# include "../objects/t_core.h"
# include "./t_render.h"
# include <math.h>
# include <stdint.h>
# include "mlx.h"
# include "libft.h"
# include "../util/fake_globals.h"
# include "../objects/objects.h"

int			render(void);
t_payload	sphere_intercetion(t_ray *ray, t_obj_base *obj);
t_payload	plane_intercetion(t_ray *ray, t_obj_base *obj);
t_payload	cylinder_intersection(t_ray *ray, t_obj_base *obj);
t_payload	trace_ray(t_ray *ray);

#endif
