/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   raycasting.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: xvoorvaa <xvoorvaa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/07 19:27:12 by xvoorvaa      #+#    #+#                 */
/*   Updated: 2022/07/18 17:44:14 by xvoorvaa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "raycast.h"
#include "cub3d.h"

#include <math.h>

#define WALL '1'

static void	set_ray_pos(t_data *data, UINT x)
{
	data->camera_x = 2 * x / (double) data->screen_width - 1;
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
	data->line_height = (int)(data->screen_height / data->perp_wall_dist);
	data->draw_start = data->screen_height / 2 - data->line_height / 2;
	if (data->draw_start < 0)
		data->draw_start = 0;
	data->draw_end = data->line_height / 2 + data->screen_height / 2;
	if (data->draw_end >= (int) data->screen_height)
		data->draw_end = data->screen_height - 1;
}

static void	calculate_texture(t_data *data, mlx_texture_t *wall, char *world_map[])
{
	data->tex_height = wall->height;
	data->tex_width = wall->width;
	data->tex_num = world_map[data->map_y][data->map_x] - 1;
	if (data->side == 0)
		data->wall_x = data->pos_y + data->perp_wall_dist * data->raydir_y;
	else
		data->wall_x = data->pos_x + data->perp_wall_dist * data->raydir_x;
	data->wall_x -= floor((data->wall_x));
	data->tex_x = (int) (data->wall_x * (double) data->tex_width);
	if (data->side == 0 && data->raydir_x > 0)
		data->tex_x = data->tex_width - data->tex_x - 1;
	if (data->side == 1 && data->raydir_y < 0)
		data->tex_x = data->tex_width - data->tex_x - 1;
	data->step = 1.0 * data->tex_height / data->line_height;
	data->tex_pos = (data->draw_start - data->screen_height / 2 + data->line_height / 2) * data->step;
}

void	raycasting_hook(void *param)
{
	unsigned int	x;
	t_vars			*vars;

	x = 0;
	vars = param;
	reset_window(vars->textures.screen);
	my_mlx_resize_window(vars->mlx, &vars->data, vars->textures.screen);
	while (x < vars->data.screen_width)
	{
		set_ray_pos(&vars->data, x);
		set_ray_delta(&vars->data);
		perform_dda(&vars->data, vars->map_data.world_map);
		calculate_height(&vars->data);
		if (vars->data.side == 0 && vars->data.step_x < 0)
		{
			calculate_texture(&vars->data, vars->textures.east_wall, vars->map_data.world_map);
			draw_wall(&vars->data, vars->textures.screen, vars->textures.east_wall, x);
		}
		if (vars->data.side == 0 && vars->data.step_x > 0)
		{
			calculate_texture(&vars->data, vars->textures.west_wall, vars->map_data.world_map);
			draw_wall(&vars->data, vars->textures.screen, vars->textures.west_wall, x);
		}
		if (vars->data.side == 1 && vars->data.step_y > 0)
		{
			calculate_texture(&vars->data, vars->textures.south_wall, vars->map_data.world_map);
			draw_wall(&vars->data, vars->textures.screen, vars->textures.south_wall, x);
		}
		if (vars->data.side == 1 && vars->data.step_y < 0)
		{
			calculate_texture(&vars->data, vars->textures.north_wall, vars->map_data.world_map);
			draw_wall(&vars->data, vars->textures.screen, vars->textures.north_wall, x);
		}
		x++;
	}
}
