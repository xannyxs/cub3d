/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_unknown.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: xvoorvaa <xvoorvaa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/07 17:36:20 by xvoorvaa      #+#    #+#                 */
/*   Updated: 2022/06/07 17:37:06 by xvoorvaa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

#define WALL '1'
#define EMPTY '0'

int	check_unknown(t_map map_data)
{
	unsigned int	x;
	unsigned int	y;

	x = 0;
	y = 1;
	while (y < map_data.height)
	{
		while (map_data.world_map[y][x])
		{
			if (map_data.world_map[y][x] != EMPTY && \
				map_data.world_map[y][x] != WALL && \
				map_data.world_map[y][x] != 'N' && \
				map_data.world_map[y][x] != 'E' && \
				map_data.world_map[y][x] != 'S' && \
				map_data.world_map[y][x] != 'W' && \
				map_data.world_map[y][x] != ' ')
				return (ERROR);
			x++;
		}
		x = 0;
		y++;
	}
	return (SUCCES);
}