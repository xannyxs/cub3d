/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   draw.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: xvoorvaa <xvoorvaa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/09 16:13:36 by xvoorvaa      #+#    #+#                 */
/*   Updated: 2022/07/27 18:52:35 by swofferh      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "MLX42/MLX42.h"
#include "libft.h" /* ft_memset */

/*
	Colour input: R, G, B, Transparent
	Get value by bitshifting the decimal to hexadecimal.
*/
static uint32_t	create_rgb(int r, int g, int b)
{
	return (r << 24 | g << 16 | b << 8 | 255);
}

void	reset_window(mlx_image_t *screen)
{
	ft_memset(screen->pixels, 0, screen->width * screen->height * sizeof(int));
}

static void	draw_ceiling(mlx_image_t *screen, int draw_start, t_textures t, \
	int x)
{
	UINT		y;
	uint32_t	colour;

	y = 0;
	colour = create_rgb(t.c_rgb[0], t.c_rgb[1], t.c_rgb[2]);
	while (y <= (UINT) draw_start && y < HEIGHT)
	{
		mlx_put_pixel(screen, x, y, colour);
		y++;
	}
}

void	draw_floor(mlx_image_t *screen, int draw_end, t_textures texture, \
	int x)
{
	UINT		y;
	uint32_t	colour;

	y = draw_end;
	colour = create_rgb(texture.f_rgb[0], texture.f_rgb[1], texture.f_rgb[2]);
	while (y < screen->height - 1)
	{
		mlx_put_pixel(screen, x, y, colour);
		y++;
	}
}

/*
	Draws vertical lines from top to y value (bit by bit - pixels)
		first ceiling then floor then process RGB colours.
		Using two adapted mlx functions (upgraded)
*/
void	draw_wall(t_data *data, t_textures texture, \
	mlx_texture_t *wall, UINT x)
{
	int	y_wall;

	y_wall = data->draw_start;
	draw_ceiling(texture.screen, data->draw_start, texture, x);
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
	draw_floor(texture.screen, data->draw_end, texture, x);
}
