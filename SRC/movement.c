/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   movement.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: xvoorvaa <xvoorvaa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/10 14:24:22 by xvoorvaa      #+#    #+#                 */
/*   Updated: 2022/06/16 18:20:40 by xvoorvaa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "MLX42/MLX42.h"

#include <math.h> /* cos, sin */
#include <stdio.h>
#include "libft.h"

#define ROT_SPEED 0.05
#define MOVE_SPEED 0.05

static void	key_player_rotation(t_vars *vars)
{
	if (mlx_is_key_down(vars->mlx, MLX_KEY_LEFT))
	{
		double old_dir_x;
		double old_plane_x;

		old_dir_x = vars->data.dir_x;
		old_plane_x = vars->data.plane_x;
		vars->data.dir_x = vars->data.dir_x * cos(ROT_SPEED) - vars->data.dir_y * sin(ROT_SPEED);
		vars->data.dir_y = old_dir_x * sin(ROT_SPEED) +  vars->data.dir_y * cos(ROT_SPEED);
		vars->data.plane_x = vars->data.plane_x * cos(ROT_SPEED) - vars->data.plane_y * sin(ROT_SPEED);
		vars->data.plane_y = old_plane_x * sin(ROT_SPEED) + vars->data.plane_y * cos(ROT_SPEED);
	}
	if (mlx_is_key_down(vars->mlx, MLX_KEY_RIGHT))
	{
		double old_dir_x;
		double old_plane_x;

		old_dir_x = vars->data.dir_x;
		old_plane_x = vars->data.plane_x;
		vars->data.dir_x = vars->data.dir_x * cos(-ROT_SPEED) - vars->data.dir_y * sin(-ROT_SPEED);
		vars->data.dir_y = old_dir_x * sin(-ROT_SPEED) + vars->data.dir_y * cos(-ROT_SPEED);
		vars->data.plane_x = vars->data.plane_x * cos(-ROT_SPEED) - vars->data.plane_y * sin(-ROT_SPEED);
		vars->data.plane_y = old_plane_x * sin(-ROT_SPEED) + vars->data.plane_y * cos(-ROT_SPEED);
	}
}

static void	key_player_movement(t_vars *vars)
{
	if (mlx_is_key_down(vars->mlx, MLX_KEY_S))
	{
		if (vars->map_data.world_map[(int)(vars->data.pos.y)][(int)(vars->data.pos.x - vars->data.dir_x * MOVE_SPEED)] == '0')
			vars->data.pos.x -= vars->data.dir_x * MOVE_SPEED;
		if (vars->map_data.world_map[(int)(vars->data.pos.y - vars->data.dir_y * MOVE_SPEED)][(int)(vars->data.pos.x)] == '0')
			vars->data.pos.y -= vars->data.dir_y * MOVE_SPEED;
	}
	if (mlx_is_key_down(vars->mlx, MLX_KEY_W))
	{
		if (vars->map_data.world_map[(int)(vars->data.pos.y)][(int)(vars->data.pos.x + vars->data.dir_x * MOVE_SPEED)] == '0')
			vars->data.pos.x += vars->data.dir_x * MOVE_SPEED;
		if (vars->map_data.world_map[(int)(vars->data.pos.y + vars->data.dir_y * MOVE_SPEED)][(int)(vars->data.pos.x)] == '0')
			vars->data.pos.y += vars->data.dir_y * MOVE_SPEED;
	}
}

void	movement_hook(void *param)
{
	t_vars	*vars;

	vars = param;
	if (mlx_is_key_down(vars->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(vars->mlx);
	key_player_movement(vars);
	key_player_rotation(vars);
}