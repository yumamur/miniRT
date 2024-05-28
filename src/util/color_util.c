/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yumamur <yumamur@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 17:19:12 by yumamur           #+#    #+#             */
/*   Updated: 2024/05/28 17:19:13 by yumamur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../vector/t_vector.h"

int	color_vf_int(t_vf3 clr, int o)
{
	int	r;
	int	g;
	int	b;

	r = (int)(clr.r * 255.0f);
	g = (int)(clr.g * 255.0f);
	b = (int)(clr.b * 255.0f);
	return (o << 24 | r << 16 | g << 8 | b);
}

int	calc_color(int prev_color, int new_color, int j)
{
	int	r;
	int	g;
	int	b;
	int	o;

	o = (prev_color >> 24) & 0xff;
	r = (((prev_color >> 16) & 0xff) * j + ((new_color >> 16) & 0xff))
		/ (j + 1);
	g = (((prev_color >> 8) & 0xff) * j + ((new_color >> 8) & 0xff)) / (j + 1);
	b = ((prev_color & 0xff) * j + (new_color & 0xff)) / (j + 1);
	return (o << 24 | r << 16 | g << 8 | b);
}
