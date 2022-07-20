/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   raycasting_utils.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: xvoorvaa <xvoorvaa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/19 22:07:09 by xvoorvaa      #+#    #+#                 */
/*   Updated: 2022/07/20 16:59:14 by swofferh      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "MLX42/MLX42.h"

#include <math.h> /* floor */

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
		draw_wall(data, textures, textures.east_wall, x);
	}
	if (data->side == 0 && data->step_x > 0)
	{
		calc_texture(data, textures.west_wall, map_data.world_map);
		draw_wall(data, textures, textures.west_wall, x);
	}
	if (data->side == 1 && data->step_y > 0)
	{
		calc_texture(data, textures.south_wall, map_data.world_map);
		draw_wall(data, textures, textures.south_wall, x);
	}
	if (data->side == 1 && data->step_y < 0)
	{
		calc_texture(data, textures.north_wall, map_data.world_map);
		draw_wall(data, textures, textures.north_wall, x);
	}
}
