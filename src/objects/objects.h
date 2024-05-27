/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yumamur <yumamur@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 23:22:47 by yumamur           #+#    #+#             */
/*   Updated: 2024/05/27 18:53:41 by yumamur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECTS_H
# define OBJECTS_H

# include "t_core.h"
# include "t_obj.h"
# include "t_light.h"
# include "libft.h"

_Bool			is_scene_valid(void);
void			clean_scene(void);

t_camera		*new_camera(t_vf3 position, t_vf3 orientation, float fov);
t_light_base	*new_ambient_light(float ratio, t_vf3 color);
t_light_base	*new_point_light(t_vf3 position, float intensity, t_vf3 color);
t_light_base	*new_spot_light(t_vf3 position, t_vf3 direction,
					t_vf2 xint_yangle, t_vf3 color);

t_obj_base		*new_sphere(float radius, t_obj_base base);
t_obj_base		*new_plane(t_obj_base base);
t_obj_base		*new_cylinder(float radius, float height, t_obj_base base);
t_obj_base		*new_cone(float radius, float height, t_obj_base base);

t_camera		*get_camera(int i);
t_light_base	*get_directional_light();
t_ambient_light	*get_ambient_light(void);

#endif
