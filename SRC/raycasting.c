/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   raycasting.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: xvoorvaa <xvoorvaa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/07 19:27:12 by xvoorvaa      #+#    #+#                 */
/*   Updated: 2022/06/09 15:04:59 by xvoorvaa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	raycasting_hook(void *param)
{
	int		x;
	t_vars	*vars;

	x = 0;
	vars = param;
	while (x < WIDTH)
	{
		vars->data.camera_x = 2 * x / WIDTH - 1;
		vars->data.raydir_x = vars->data.dir_x + vars->data.plane_x * vars->data.camera_x;
		vars->data.raydir_y = vars->data.dir_y + vars->data.plane_y * vars->data.camera_x;
		x++;
	}
}