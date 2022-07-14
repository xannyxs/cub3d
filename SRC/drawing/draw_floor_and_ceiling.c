/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   draw_floor_and_ceiling.c                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: xvoorvaa <xvoorvaa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/17 12:05:52 by xvoorvaa      #+#    #+#                 */
/*   Updated: 2022/06/27 14:12:15 by xvoorvaa      ########   odam.nl         */
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
