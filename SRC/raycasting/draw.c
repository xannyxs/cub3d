/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   draw.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: xvoorvaa <xvoorvaa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/09 16:13:36 by xvoorvaa      #+#    #+#                 */
/*   Updated: 2022/07/26 20:59:41 by xvoorvaa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "MLX42/MLX42.h"
#include "libft.h" /* ft_memset */

/*
	Get colour value by bitshifting the decimal to hexadecimal.
*/
static uint32_t	create_rgb(int r, int g, int b)
{
	return (r << 24 | g << 16 | b << 8 | 255);
}

void	reset_window(mlx_image_t *screen)
{
	ft_memset(screen->pixels, 0, screen->width * screen->height * sizeof(int));
}

void	draw_ceiling(mlx_image_t *screen, int draw_start, uint32_t color, int x)
{
	UINT	y;

	y = 0;
	while (y <= (UINT) draw_start && y < HEIGHT)
	{
		mlx_put_pixel(screen, x, y, color);
		y++;
	}
}

void	draw_floor(mlx_image_t *screen, int draw_end, uint32_t color, int x)
{
	UINT	y;

	y = draw_end;
	while (y < screen->height - 1)
	{
		mlx_put_pixel(screen, x, y, color);
		y++;
	}
}

/*
	Colour input: R, G, B, Transparent
*/
void	draw_wall(t_data *data, t_textures texture, \
	mlx_texture_t *wall, UINT x)
{
	int	y_wall;

	y_wall = data->draw_start;
	draw_ceiling(texture.screen, data->draw_start, \
		create_rgb(texture.c_rgb[0], texture.c_rgb[1], texture.c_rgb[2]), x);
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
	draw_floor(texture.screen, data->draw_end, \
		create_rgb(texture.f_rgb[0], texture.f_rgb[1], texture.f_rgb[2]), x);
}
