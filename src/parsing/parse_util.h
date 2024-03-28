/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_util.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yumamur <yumamur@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 21:02:58 by yumamur           #+#    #+#             */
/*   Updated: 2024/03/28 21:02:59 by yumamur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_UTIL_H
# define PARSE_UTIL_H

# include "../vector/t_vector.h"

_Bool	float_from_str(char *str, float *addr);
_Bool	normal_float_from_str(char *str, float *addr);

_Bool	color_from_str(char *str, t_vf3 *addr);
_Bool	vf3_from_str(char *str, t_vf3 *addr);
_Bool	normal_vf3_from_str(char *str, t_vf3 *addr);

#endif