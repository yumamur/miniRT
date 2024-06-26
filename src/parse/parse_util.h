/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_util.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yumamur <yumamur@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 21:02:58 by yumamur           #+#    #+#             */
/*   Updated: 2024/05/15 18:27:05 by yumamur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_UTIL_H
# define PARSE_UTIL_H

# include "../vector/t_vector.h"

void	*str_to_wordtab(void *line);

_Bool	valid_atof(char *str, float *addr);
_Bool	valid_normal_atof(char *str, float *addr);

_Bool	valid_ato_rgb(char *str, t_vf3 *addr);
_Bool	valid_ato_vf3(char *str, t_vf3 *addr);
_Bool	valid_normal_ato_vf3(char *str, t_vf3 *addr);

#endif
