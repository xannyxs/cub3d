/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   movement.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: xvoorvaa <xvoorvaa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/10 14:24:22 by xvoorvaa      #+#    #+#                 */
/*   Updated: 2022/06/20 15:05:14 by xvoorvaa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "MLX42/MLX42.h"

#include <math.h> /* cos, sin */

#define TURN 0.05
#define WALK 0.06 /* Cannot be lower than 0.06 */

/*
	Rotating the player.
	TURN is the rotation speed of the player.
*/
static void	player_rotation(mlx_t *mlx, t_data *s)
{
	double	old_dir_x;
	double	old_plane_x;

	if (mlx_is_key_down(mlx, MLX_KEY_LEFT))
	{
		old_dir_x = s->dir_x;
		old_plane_x = s->plane_x;
		s->dir_x = s->dir_x * cos(TURN) - s->dir_y * sin(TURN);
		s->dir_y = old_dir_x * sin(TURN) + s->dir_y * cos(TURN);
		s->plane_x = s->plane_x * cos(TURN) - s->plane_y * sin(TURN);
		s->plane_y = old_plane_x * sin(TURN) + s->plane_y * cos(TURN);
	}
	if (mlx_is_key_down(mlx, MLX_KEY_RIGHT))
	{
		old_dir_x = s->dir_x;
		old_plane_x = s->plane_x;
		s->dir_x = s->dir_x * cos(-TURN) - s->dir_y * sin(-TURN);
		s->dir_y = old_dir_x * sin(-TURN) + s->dir_y * cos(-TURN);
		s->plane_x = s->plane_x * cos(-TURN) - s->plane_y * sin(-TURN);
		s->plane_y = old_plane_x * sin(-TURN) + s->plane_y * cos(-TURN);
	}
}

/*
	For more information about strafing:
	Check: https://en.wikipedia.org/wiki/Strafing_(video_games)
*/
static void	strafing_movement(mlx_t *mlx, char *map[], t_data *s)
{
	if (mlx_is_key_down(mlx, MLX_KEY_A))
	{
		if (map[(int)(s->pos_y)][(int)(s->pos_x - s->dir_y * WALK)] == '0')
			s->pos_x -= s->dir_y * WALK;
		if (map[(int)(s->pos_y + s->dir_x * WALK)][(int)(s->pos_x)] == '0')
			s->pos_y += s->dir_x * WALK;
	}
	if (mlx_is_key_down(mlx, MLX_KEY_D))
	{
		if (map[(int)(s->pos_y)][(int)(s->pos_x + s->dir_y * WALK)] == '0')
			s->pos_x += s->dir_y * WALK;
		if (map[(int)(s->pos_y - s->dir_x * WALK)][(int)(s->pos_x)] == '0')
			s->pos_y -= s->dir_x * WALK;
	}
}

static void	walk_movement(mlx_t *mlx, char *map[], t_data *s)
{
	if (mlx_is_key_down(mlx, MLX_KEY_S))
	{
		if (map[(int)(s->pos_y)][(int)(s->pos_x - s->dir_x * WALK)] == '0')
			s->pos_x -= s->dir_x * WALK;
		if (map[(int)(s->pos_y - s->dir_y * WALK)][(int)(s->pos_x)] == '0')
			s->pos_y -= s->dir_y * WALK;
	}
	if (mlx_is_key_down(mlx, MLX_KEY_W))
	{
		if (map[(int)(s->pos_y)][(int)(s->pos_x + s->dir_x * WALK)] == '0')
			s->pos_x += s->dir_x * WALK;
		if (map[(int)(s->pos_y + s->dir_y * WALK)][(int)(s->pos_x)] == '0')
			s->pos_y += s->dir_y * WALK;
	}
}

/*
	Movement of player
		W - forward
		S - backward
		A - left
		D - right

	'Cuz of norm ;(
		World_map = map;
		t_data *s = *data;
*/
static void	player_movement(mlx_t *mlx, char *map[], t_data *s)
{
	walk_movement(mlx, map, s);
	strafing_movement(mlx, map, s);
}

void	movement_hook(void *param)
{
	t_vars	*vars;

	vars = param;
	if (mlx_is_key_down(vars->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(vars->mlx);
		player_movement(vars->mlx, vars->map_data.world_map, &vars->data);
		player_rotation(vars->mlx, &vars->data);
}
