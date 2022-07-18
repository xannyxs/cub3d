/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   set_delta_dist.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: xvoorvaa <xvoorvaa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/16 20:41:03 by xvoorvaa      #+#    #+#                 */
/*   Updated: 2022/07/18 17:37:51 by xvoorvaa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "raycast.h"

#include <math.h> /* Fabs */

void	set_delta_dist(t_data *data)
{
	if (data->raydir_x == 0)
		data->delta_dist_x = 1e30;
	else
		data->delta_dist_x = fabs(1 / data->raydir_x);
	if (data->raydir_y == 0)
		data->delta_dist_y = 1e30;
	else
		data->delta_dist_y = fabs(1 / data->raydir_y);
}
