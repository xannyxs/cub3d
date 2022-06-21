/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   draw.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: xvoorvaa <xvoorvaa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/09 16:13:36 by xvoorvaa      #+#    #+#                 */
/*   Updated: 2022/06/21 16:48:04 by xvoorvaa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "MLX42/MLX42.h"
#include "libft.h"

void	reset_window(mlx_image_t *screen)
{
	ft_memset(screen->pixels, 0, screen->width * screen->height * sizeof(int));
}

/*
	Colour input: R, G, B, Transparent
*/
void	draw_wall(t_data *data, mlx_image_t *screen, mlx_texture_t *texture, UINT x)
{
	int	y_wall;

	y_wall = data->draw_start;
	draw_ceiling(screen, data->draw_start, 0x243883FF, x);
	while (y_wall <= data->draw_end)
	{
		data->tex_y = (int) data->tex_pos;
		if (data->tex_y >= (int) texture->height)
			data->tex_y = data->tex_height - 1;
		data->tex_pos += data->step;
		my_mlx_put_pixel(screen, x, y_wall, my_mlx_get_colour(texture, data->tex_x, data->tex_y));
		y_wall++;
	}
	draw_floor(screen, data->draw_end, 0x178292FF, x);
}