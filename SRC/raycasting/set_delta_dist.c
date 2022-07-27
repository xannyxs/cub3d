/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   set_delta_dist.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: xvoorvaa <xvoorvaa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/16 20:41:03 by xvoorvaa      #+#    #+#                 */
/*   Updated: 2022/07/27 18:51:03 by swofferh      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "raycast.h"

#include <math.h> /* Fabs */

/**
 * @brief This function rounds up the numbers to absolute decimals
 * Fabs makes negative numbers positive.
 * See: https://www.programiz.com/c-programming/library-function/math.h/fabs
 * 
 * 
 * @param data fabs sets huge double vars into absolute doubles
 */
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
