/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   draw.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: xvoorvaa <xvoorvaa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/09 16:13:36 by xvoorvaa      #+#    #+#                 */
/*   Updated: 2022/06/20 12:37:19 by xvoorvaa      ########   odam.nl         */
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
void	draw_cast_south(t_vars *vars, unsigned int x)
{
	int	y_wall;

	y_wall = vars->data.draw_start;
	draw_ceiling(vars->textures.screen, vars->data.draw_start,0x243883FF, x);
	while (y_wall <= vars->data.draw_end)
	{
		mlx_put_pixel(vars->textures.screen, x, y_wall, create_rgbt(32, 16, 96, 255));
		y_wall++;
	}
	draw_floor(vars->textures.screen, vars->data.draw_end,0x178292FF, x);
}

void	draw_cast_east(t_vars *vars, unsigned int x)
{
	int	y_wall;

	y_wall = vars->data.draw_start;
	draw_ceiling(vars->textures.screen, vars->data.draw_start,0x243883FF, x);
	while (y_wall <= vars->data.draw_end)
	{
		mlx_put_pixel(vars->textures.screen, x, y_wall, create_rgbt(155, 0, 255, 255));
		y_wall++;
	}
	draw_floor(vars->textures.screen, vars->data.draw_end,0x178292FF, x);
}

void	draw_cast_north(t_vars *vars, unsigned int x)
{
	int	y_wall;

	y_wall = vars->data.draw_start;
	draw_ceiling(vars->textures.screen, vars->data.draw_start,0x243883FF, x);
	while (y_wall <= vars->data.draw_end)
	{
		mlx_put_pixel(vars->textures.screen, x, y_wall, create_rgbt(65, 32, 96, 255)); 
		y_wall++;
	}
	draw_floor(vars->textures.screen, vars->data.draw_end,0x178292FF, x);
}

void	draw_cast_west(t_vars *vars, unsigned int x)
{
	int	y_wall;

	y_wall = vars->data.draw_start;
	draw_ceiling(vars->textures.screen, vars->data.draw_start,0x243883FF, x);
	while (y_wall <= vars->data.draw_end)
	{
		mlx_put_pixel(vars->textures.screen, x, y_wall, create_rgbt(110, 0, 96, 255));
		y_wall++;
	}
	draw_floor(vars->textures.screen, vars->data.draw_end,0x178292FF, x);
}
