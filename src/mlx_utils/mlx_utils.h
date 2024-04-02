/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mugurel <mugurel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 04:24:05 by mugurel           #+#    #+#             */
/*   Updated: 2024/03/30 05:56:05 by mugurel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_UTILS_H
# define MLX_UTILS_H

# define WIDTH 400
# define HEIGHT 400

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

void    mlx_initialize(t_mlx_data *mlx_data);
void    my_mlx_pixel_put(t_mlx_data *data, int x, int y, int color);
int     create_trgb(int r, int g, int b, int o);

#endif 