/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   is_monitor_valid.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: xvoorvaa <xvoorvaa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/27 17:34:49 by xvoorvaa      #+#    #+#                 */
/*   Updated: 2022/06/27 17:35:03 by xvoorvaa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "error.h"

bool	is_monitor_valid(mlx_t *mlx)
{
	int32_t	width;
	int32_t	height;

	mlx_get_monitor_size(0, &width, &height);
	if (width < WIDTH || height < HEIGHT)
	{
		non_fatal_error(NONVALID_MONITOR);
		mlx_terminate(mlx);
		return (false);
	}
	return (true);
}