/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   draw.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: xvoorvaa <xvoorvaa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/09 16:13:36 by xvoorvaa      #+#    #+#                 */
/*   Updated: 2022/06/14 17:31:34 by xvoorvaa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_hook(void *param)
{
	int	x = 0;
	int	y = 0;
	t_vars	*vars;

	vars = param;
	while (y < 30)
	{
		while (x < 30)
		{
			// mlx_put_pixel(vars->textures.screen, x, y, 0xFFFFFF);
			x++;
		}
		x = 0;
		y++;
	}
}