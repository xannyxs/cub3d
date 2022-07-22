/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   draw_walls_floor_ceilling.c                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: xvoorvaa <xvoorvaa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/09 16:13:36 by xvoorvaa      #+#    #+#                 */
/*   Updated: 2022/07/20 17:10:32 by swofferh      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "MLX42/MLX42.h"
#include "libft.h"

uint32_t	create_rgbt(int r, int g, int b, int t)
{
	return (r << 24 | g << 16 | b << 8 | t);
}

void	draw_ceiling(mlx_image_t *screen, int draw_start, uint32_t color, int x)
{
	int	y;

	y = 0;
	while (y < draw_start)
	{
		mlx_put_pixel(screen, x, y, color);
		y++;
	}
}

void	draw_floor(mlx_image_t *screen, int draw_end, uint32_t color, int x)
{
	int	y;

	y = draw_end;
	while (y < (int) screen->height - 1)
	{
		mlx_put_pixel(screen, x, y, color);
		y++;
	}
}


void	reset_window(mlx_image_t *screen)
{
	ft_memset(screen->pixels, 0, screen->width * screen->height * sizeof(int));
}

/*
	Colour input: R, G, B, Transparent
*/
void	draw_wall(t_data *data, t_textures texture, \
	mlx_texture_t *wall, UINT x)
{
	int	y_wall;

	y_wall = data->draw_start;
	draw_ceiling(texture.screen, data->draw_start, create_rgbt(texture.c_rgb[0], texture.c_rgb[1], texture.c_rgb[2], 255), x);
	while (y_wall <= data->draw_end)
	{
		data->tex_y = (int) data->tex_pos;
		if (data->tex_y >= (int) wall->height)
			data->tex_y = data->tex_height - 1;
		data->tex_pos += data->step;
		my_mlx_put_pixel(texture.screen, x, y_wall, \
			my_mlx_get_colour(wall, data->tex_x, data->tex_y));
		y_wall++;
	}
	draw_floor(texture.screen, data->draw_end, create_rgbt(texture.f_rgb[0], texture.f_rgb[1], texture.f_rgb[2], 255), x);
}