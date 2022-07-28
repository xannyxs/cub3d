/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   raycasting.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: xvoorvaa <xvoorvaa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/07 19:27:12 by xvoorvaa      #+#    #+#                 */
/*   Updated: 2022/07/28 19:05:41 by swofferh      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

#define WALL '1'

/**
 * @brief Set the ray pos object (point of view function)
 * camera / ray / map directions
 * 
 */
static void	set_ray_pos(t_data *data, UINT x)
{
	data->camera_x = 2 * x / (double) data->screen_width - 1;
	data->raydir_x = data->dir_x + data->plane_x * data->camera_x;
	data->raydir_y = data->dir_y + data->plane_y * data->camera_x;
	data->map_x = (int) data->pos_x;
	data->map_y = (int) data->pos_y;
}

/*
	Checks how far the player is from walls (from a diagonal perspective).
	steps: to check the direction I'm walking.
	First checks for x direction, then y direction.
	See delta cast: https://lodev.org/cgtutor/raycasting.html
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

/**
 * @brief Uses math to check the distance from the player to the wall.
 *  checks what side of wall it is on
 * 
 * @param data (for side distance)
 * @param world_map (for location of wall on map)
 */
static void	perform_dda(t_data *data, char *world_map[])
{
	while (true)
	{
		if (data->side_dist_x < data->side_dist_y)
		{
			data->side_dist_x += data->delta_dist_x;
			data->map_x += data->step_x;
			data->side = EW;
		}
		else
		{
			data->side_dist_y += data->delta_dist_y;
			data->map_y += data->step_y;
			data->side = NS;
		}
		if (world_map[data->map_y][data->map_x] == WALL)
			break ;
	}
}

/**
 * @brief	uses math to check where to start drawing the walls by
 * 			splitting the lines in the middle
 * 
 * @param data 	screen_hight is for the vertical line from toop
 * 				to bottom of screen. Line_hight for how tall a
 * 				wall is (vertical line from floor to roof)
 */
static void	calculate_height(t_data *data)
{
	if (data->side == EW)
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

/**
 * @brief 
 * 	 ______________________ x (width)
 * 	|
 * 	|
 *  y (height)
 */
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
