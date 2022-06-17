/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   draw_floor_and_ceiling.c                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: xvoorvaa <xvoorvaa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/17 12:05:52 by xvoorvaa      #+#    #+#                 */
/*   Updated: 2022/06/17 15:17:16 by xvoorvaa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "MLX42/MLX42.h"
#include "libft.h"

uint32_t	create_rgbt(int r, int g, int b, int t)
{
	return (r << 24 | g << 16 | b << 8 | t);
}

void	draw_ceiling(t_data data, mlx_image_t *screen, uint32_t colour, int x)
{
	int	y;

	y = 0;
	while (y < data.draw_start)
	{
		mlx_put_pixel(screen, x, y, colour);
		y++;
	}
}

void	draw_floor(t_data data, mlx_image_t *screen, uint32_t colour, int x)
{
	int	y;

	y = data.draw_end;
	while (y < HEIGHT)
	{
		mlx_put_pixel(screen, x, y, colour);
		y++;
	}
}
