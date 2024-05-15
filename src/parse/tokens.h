/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokens.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yumamur <yumamur@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 21:03:08 by yumamur           #+#    #+#             */
/*   Updated: 2024/04/10 16:14:05 by yumamur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKENS_H
# define TOKENS_H

# define CAMERA_STR			"C"
# define AMBIENT_LIGHT_STR	"A"
# define POINT_LIGHT_STR	"L"
# define SPOT_LIGHT_STR		"sl"
# define SPHERE_STR			"sp"
# define PLANE_STR			"pl"
# define CYLINDER_STR		"cy"
# define TRIANGLE_STR		"tr"
# define CONE_STR			"cn"

int	get_key(char *key);

#endif
