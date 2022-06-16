/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   draw.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: xvoorvaa <xvoorvaa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/09 16:13:36 by xvoorvaa      #+#    #+#                 */
/*   Updated: 2022/06/16 20:37:33 by xvoorvaa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "libft.h"

void	reset_window(mlx_image_t *screen)
{
	ft_memset(screen->pixels, 0, screen->width * screen->height * sizeof(int));
}

/*
	Colour input: R, G, B, Transparent
*/
void	draw_cast_green(t_vars *vars, unsigned int x)
{
	int		y_wall;

	y_wall = vars->data.draw_start;
	while (y_wall <= vars->data.draw_end)
	{
		mlx_put_pixel(vars->textures.screen, x, y_wall, 0x32a83cFF);
		y_wall++;
		vars->data.y_tex += vars->data.y_tex_step;
	}
}

void	draw_cast_blue(t_vars *vars, unsigned int x)
{
	int		y_wall;

	y_wall = vars->data.draw_start;
	while (y_wall <= vars->data.draw_end)
	{
		mlx_put_pixel(vars->textures.screen, x, y_wall, 0xFFFFFFF);
		y_wall++;
		vars->data.y_tex += vars->data.y_tex_step;
	}
}

void	draw_cast_purple(t_vars *vars, unsigned int x)
{
	int		y_wall;

	y_wall = vars->data.draw_start;
	while (y_wall <= vars->data.draw_end)
	{
		mlx_put_pixel(vars->textures.screen, x, y_wall, 0x6532a8FF);
		y_wall++;
		vars->data.y_tex += vars->data.y_tex_step;
	}
}

void	draw_cast_red(t_vars *vars, unsigned int x)
{
	int		y_wall;

	y_wall = vars->data.draw_start;
	while (y_wall <= vars->data.draw_end)
	{
		mlx_put_pixel(vars->textures.screen, x, y_wall, 0xa8323eFF);
		y_wall++;
		vars->data.y_tex += vars->data.y_tex_step;
	}
}
