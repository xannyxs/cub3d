/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   movement.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: xvoorvaa <xvoorvaa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/10 14:24:22 by xvoorvaa      #+#    #+#                 */
/*   Updated: 2022/06/17 14:19:21 by xvoorvaa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "MLX42/MLX42.h"

#include <math.h> /* cos, sin */

#define ROT_SPEED 0.05
#define MOVE_SPEED 0.05

/*
	Rotating the player.
	ROT_SPEED is the rotation speed of the player.
*/
static void	key_player_rotation(mlx_t *mlx, t_data *data)
{
	double	old_dir_x;
	double	old_plane_x;

	if (mlx_is_key_down(mlx, MLX_KEY_LEFT))
	{
		old_dir_x = data->dir_x;
		old_plane_x = data->plane_x;
		data->dir_x = data->dir_x * cos(ROT_SPEED) - data->dir_y * sin(ROT_SPEED);
		data->dir_y = old_dir_x * sin(ROT_SPEED) + data->dir_y * cos(ROT_SPEED);
		data->plane_x = data->plane_x * cos(ROT_SPEED) - data->plane_y * sin(ROT_SPEED);
		data->plane_y = old_plane_x * sin(ROT_SPEED) + data->plane_y * cos(ROT_SPEED);
	}
	if (mlx_is_key_down(mlx, MLX_KEY_RIGHT))
	{
		old_dir_x = data->dir_x;
		old_plane_x = data->plane_x;
		data->dir_x = data->dir_x * cos(-ROT_SPEED) - data->dir_y * sin(-ROT_SPEED);
		data->dir_y = old_dir_x * sin(-ROT_SPEED) + data->dir_y * cos(-ROT_SPEED);
		data->plane_x = data->plane_x * cos(-ROT_SPEED) - data->plane_y * sin(-ROT_SPEED);
		data->plane_y = old_plane_x * sin(-ROT_SPEED) + data->plane_y * cos(-ROT_SPEED);
	}
}

/*
	Movement of player
	W - forward
	S - backward
	A - left
	D - right
*/
static void	key_player_movement(mlx_t *mlx, char *world_map[], t_data *data)
{
	if (mlx_is_key_down(mlx, MLX_KEY_S))
	{
		if (world_map[(int)(data->pos_y)][(int)(data->pos_x - data->dir_x * MOVE_SPEED)] == '0')
			data->pos_x -= data->dir_x * MOVE_SPEED;
		if (world_map[(int)(data->pos_y - data->dir_y * MOVE_SPEED)][(int)(data->pos_x)] == '0')
			data->pos_y -= data->dir_y * MOVE_SPEED;
	}
	if (mlx_is_key_down(mlx, MLX_KEY_W))
	{
		if (world_map[(int)(data->pos_y)][(int)(data->pos_x + data->dir_x * MOVE_SPEED)] == '0')
			data->pos_x += data->dir_x * MOVE_SPEED;
		if (world_map[(int)(data->pos_y + data->dir_y * MOVE_SPEED)][(int)(data->pos_x)] == '0')
			data->pos_y += data->dir_y * MOVE_SPEED;
	}
	if (mlx_is_key_down(mlx, MLX_KEY_A))
	{
		if (world_map[(int)(data->pos_y)][(int)(data->pos_x + data->dir_y * MOVE_SPEED)] == '0')
			data->pos_x += data->dir_y * MOVE_SPEED;
		if (world_map[(int)(data->pos_y + data->dir_x * MOVE_SPEED)][(int)(data->pos_x)] == '0')
			data->pos_y += data->dir_x * MOVE_SPEED;
	}
	if (mlx_is_key_down(mlx, MLX_KEY_D))
	{
		if (world_map[(int)(data->pos_y)][(int)(data->pos_x - data->dir_y * MOVE_SPEED)] == '0')
			data->pos_x -= data->dir_y * MOVE_SPEED;
		if (world_map[(int)(data->pos_y - data->dir_x * MOVE_SPEED)][(int)(data->pos_x)] == '0')
			data->pos_y -= data->dir_x * MOVE_SPEED;
	}
}

void	movement_hook(void *param)
{
	t_vars	*vars;

	vars = param;
	if (mlx_is_key_down(vars->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(vars->mlx);
	key_player_movement(vars->mlx, vars->map_data.world_map, &vars->data);
	key_player_rotation(vars->mlx, &vars->data);
}
