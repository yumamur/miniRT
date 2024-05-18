/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yumamur <yumamur@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 04:24:05 by mugurel           #+#    #+#             */
/*   Updated: 2024/05/16 07:36:15 by yumamur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_UTILS_H
# define MLX_UTILS_H

# define WIDTH 900
# define HEIGHT 600

# include <stdint.h>

typedef struct s_mlx_data
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_mlx_data;

void		mlx_initialize(void);
void		my_mlx_pixel_put(int x, int y, int color);
int			create_trgb(int r, int g, int b, int o);
void		put_current_img(void);
uint32_t	*get_pixel(int x, int y);

#endif
