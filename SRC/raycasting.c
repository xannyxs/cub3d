/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   raycasting.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: xvoorvaa <xvoorvaa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/07 19:27:12 by xvoorvaa      #+#    #+#                 */
/*   Updated: 2022/06/10 14:21:11 by xvoorvaa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

#include <stdio.h>

void	set_ray_pos(t_data *data, unsigned int x)
{
	data->camera_x = 2 * x / WIDTH - 1;
	data->raydir_x = data->dir_x + data->plane_x * data->camera_x;
	data->raydir_y = data->dir_y + data->plane_y * data->camera_x;
	data->map_x = (int) data->pos_x;
	data->map_y = (int) data->pos_y;
}

/*
	Checks how far the player is from a wall.
	See video: https://www.youtube.com/watch?v=NbSee-XM7WA
*/
void	set_ray_delta(t_data *data)
{
	data->delta_dist_x = 1 / data->raydir_x;
	data->delta_dist_y = 1 / data->raydir_y;
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

void	perform_DDA(t_vars *vars)
{
	while (vars->data->hit == false)
	{
		if (vars->data->side_dist_x < vars->data->side_dist_y)
		{
			vars->data->side_dist_x += vars->data->delta_dist_x;
			vars->data->map_x += vars->data->step_x;
			vars->data->side = 0;
		}
		else
		{
			vars->data->side_dist_y += vars->data->delta_dist_y;
			vars->data->map_y += vars->data->step_y;
			vars->data->side = 1;
		}
		if (vars->map_data.world_map[vars->data->map_x][vars->data->map_y] > 0)
			vars->data->hit = true;
	} 
}

void	raycasting_hook(void *param)
{
	unsigned int	x;
	t_vars			*vars;

	x = 0;
	vars = param;
	while (x < WIDTH)
	{
		set_ray_pos(vars->data, x);
		x++;
	}
}
