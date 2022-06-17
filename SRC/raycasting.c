/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   raycasting.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: xvoorvaa <xvoorvaa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/07 19:27:12 by xvoorvaa      #+#    #+#                 */
/*   Updated: 2022/06/17 15:09:24 by xvoorvaa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "raycast.h"
#include "cub3d.h"

#define WALL '1'

static void	set_ray_pos(t_data *data, unsigned int x)
{
	data->camera_x = 2 * x / (double) WIDTH - 1;
	data->raydir_x = data->dir_x + data->plane_x * data->camera_x;
	data->raydir_y = data->dir_y + data->plane_y * data->camera_x;
	data->map_x = (int) data->pos_x;
	data->map_y = (int) data->pos_y;
}

/*
	Checks how far the player is from a wall.
	See video: https://www.youtube.com/watch?v=NbSee-XM7WA
*/
static void	set_ray_delta(t_data *data)
{
	set_delta_dist(data);
	if (data->raydir_x < 0)
	{
		data->step_x = -1;
		data->side_dist_x = (data->pos_x - data->map_x) * data->delta_dist_x;
	}
	else
	{
		data->step_x = 1;
		data->side_dist_x = (data->map_x + 1.0 - data->pos_x) * data->delta_dist_x;
	}
	if (data->raydir_y < 0)
	{
		data->step_y = -1;
		data->side_dist_y = (data->pos_y - data->map_y) * data->delta_dist_y;
	}
	else
	{
		data->step_y = 1;
		data->side_dist_y = (data->map_y + 1.0 - data->pos_y) * data->delta_dist_y;
	}
}

static void	perform_dda(t_data *data, char *world_map[])
{
	while (true)
	{
		if (data->side_dist_x < data->side_dist_y)
		{
			data->side_dist_x += data->delta_dist_x;
			data->map_x += data->step_x;
			data->side = 0;
		}
		else
		{
			data->side_dist_y += data->delta_dist_y;
			data->map_y += data->step_y;
			data->side = 1;
		}
		if (world_map[data->map_y][data->map_x] == WALL)
			break ;
	}
}

static void	calculate_height(t_data *data)
{
	if (data->side == 0)
		data->perp_wall_dist = data->side_dist_x - data->delta_dist_x;
	else
		data->perp_wall_dist = data->side_dist_y - data->delta_dist_y;
	data->line_height = (int)(HEIGHT / data->perp_wall_dist);
	data->draw_start = HEIGHT / 2 - data->line_height / 2;
	if (data->draw_start < 0)
		data->draw_start = 0;
	data->draw_end = data->line_height / 2 + HEIGHT / 2;
	if (data->draw_end >= HEIGHT)
		data->draw_end = HEIGHT - 1;
}

void	raycasting_hook(void *param)
{
	unsigned int	x;
	t_vars			*vars;

	x = 0;
	vars = param;
	reset_window(vars->textures.screen);
	while (x < WIDTH)
	{
		set_ray_pos(&vars->data, x);
		set_ray_delta(&vars->data);
		perform_dda(&vars->data, vars->map_data.world_map);
		calculate_height(&vars->data);
		if (vars->data.side == 0 && vars->data.step_x < 0)
			draw_cast_east(vars, x);
		if (vars->data.side == 0 && vars->data.step_x > 0)
			draw_cast_west(vars, x);
		if (vars->data.side == 1 && vars->data.step_y > 0)
			draw_cast_south(vars, x);
		if (vars->data.side == 1 && vars->data.step_y < 0)
			draw_cast_north(vars, x);
		x++;
	}
}
