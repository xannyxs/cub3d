/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   movement.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: xvoorvaa <xvoorvaa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/10 14:24:22 by xvoorvaa      #+#    #+#                 */
/*   Updated: 2022/06/14 19:06:04 by xvoorvaa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "MLX42/MLX42.h"

#include <stdio.h>

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
		// printf("X: %d, Y: %d\n", (int)(vars->data.pos_x + vars->data.dir_x * MOVE_SPEED), (int)(vars->data.pos_y));
		printf("POS: %d\n", vars->map_data.world_map[(int)(vars->data.pos_x + vars->data.dir_x * MOVE_SPEED)][(int)(vars->data.pos_y)] == false);
		printf("%f\n", vars->data.pos_x);
		if (vars->map_data.world_map[(int)(vars->data.pos_x + vars->data.dir_x * MOVE_SPEED)][(int)(vars->data.pos_y)] == false)
		{
			printf("Test\n");
			vars->data.pos_x += vars->data.dir_x * MOVE_SPEED;
		}
		if (vars->map_data.world_map[(int)(vars->data.pos_x)][(int)(vars->data.pos_y + vars->data.dir_y * MOVE_SPEED)] == false)
			vars->data.pos_y += vars->data.dir_y * MOVE_SPEED;
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