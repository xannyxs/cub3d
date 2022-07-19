/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   raycasting.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: xvoorvaa <xvoorvaa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/07 19:27:12 by xvoorvaa      #+#    #+#                 */
/*   Updated: 2022/07/19 20:06:09 by xvoorvaa      ########   odam.nl         */
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
static void	set_ray_delta(t_data *d)
{
	set_delta_dist(d);
	if (d->raydir_x < 0)
	{
		d->step_x = -1;
		d->side_dist_x = (d->pos_x - d->map_x) * d->delta_dist_x;
	}
	else
	{
		d->step_x = 1;
		d->side_dist_x = (d->map_x + 1.0 - d->pos_x) * d->delta_dist_x;
	}
	if (d->raydir_y < 0)
	{
		d->step_y = -1;
		d->side_dist_y = (d->pos_y - d->map_y) * d->delta_dist_y;
	}
	else
	{
		d->step_y = 1;
		d->side_dist_y = (d->map_y + 1.0 - d->pos_y) * d->delta_dist_y;
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

static void	calc_texture(t_data *d, mlx_texture_t *wall, char *world_map[])
{
	d->tex_height = wall->height;
	d->tex_width = wall->width;
	d->tex_num = world_map[d->map_y][d->map_x] - 1;
	if (d->side == 0)
		d->wall_x = d->pos_y + d->perp_wall_dist * d->raydir_y;
	else
		d->wall_x = d->pos_x + d->perp_wall_dist * d->raydir_x;
	d->wall_x -= floor((d->wall_x));
	d->tex_x = (int)(d->wall_x * (double) d->tex_width);
	if (d->side == 0 && d->raydir_x > 0)
		d->tex_x = d->tex_width - d->tex_x - 1;
	if (d->side == 1 && d->raydir_y < 0)
		d->tex_x = d->tex_width - d->tex_x - 1;
	d->step = 1.0 * d->tex_height / d->line_height;
	d->tex_pos = (d->draw_start - d->screen_height / 2 + d->line_height / 2) \
		* d->step;
}

void	side_of_wall(t_data *data, t_textures textures, t_map map_data, UINT x)
{
	if (data->side == 0 && data->step_x < 0)
	{
		calc_texture(data, textures.east_wall, map_data.world_map);
		draw_wall(data, textures.screen, textures.east_wall, x);
	}
	if (data->side == 0 && data->step_x > 0)
	{
		calc_texture(data, textures.west_wall, map_data.world_map);
		draw_wall(data, textures.screen, textures.west_wall, x);
	}
	if (data->side == 1 && data->step_y > 0)
	{
		calc_texture(data, textures.south_wall, map_data.world_map);
		draw_wall(data, textures.screen, textures.south_wall, x);
	}
	if (data->side == 1 && data->step_y < 0)

	{
		calc_texture(data, textures.north_wall, map_data.world_map);
		draw_wall(data, textures.screen, textures.north_wall, x);
	}
}

void	raycasting_hook(void *param)
{
	UINT	x;
	t_vars	*vars;

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
		side_of_wall(&vars->data, vars->textures, vars->map_data, x);
		x++;
	}
}
