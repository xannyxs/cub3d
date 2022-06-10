/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   movement.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: xvoorvaa <xvoorvaa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/10 14:24:22 by xvoorvaa      #+#    #+#                 */
/*   Updated: 2022/06/10 14:25:53 by xvoorvaa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "MLX42/MLX42.h"

// WIP
void	movement_hook(void *param)
{
	t_vars	*vars;

	vars = param;
	if (mlx_is_key_down(vars->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(vars->mlx);
	if (mlx_is_key_down(vars->mlx, MLX_KEY_S))
	{
		vars->textures.screen->instances[0].y += 5;
	}
	if (mlx_is_key_down(vars->mlx, MLX_KEY_W))
	{
		vars->textures.screen->instances[0].y -= 5;
	}
	if (mlx_is_key_down(vars->mlx, MLX_KEY_A))
	{
		vars->textures.screen->instances[0].x -= 5;
	}
	if (mlx_is_key_down(vars->mlx, MLX_KEY_D))
	{
		vars->textures.screen->instances[0].x += 5;
	}
}