/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   is_wall_enclosed.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: xvoorvaa <xvoorvaa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/17 13:35:38 by xvoorvaa      #+#    #+#                 */
/*   Updated: 2022/07/19 22:36:35 by xvoorvaa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "error.h"

#define WALL '1'

static int	trace_next_wall_under(char *world_map[], UINT x, UINT y)
{
	UINT	temp_x;

	temp_x = ft_strlen(world_map[y + 1]);
	while (temp_x <= x)
	{
		x--;
		if (world_map[y][x] != WALL && ft_isspace(world_map[y][x]) == false)
		{
			non_fatal_error(MISSING_WALL);
			exit(ERROR);
		}
	}
	return (temp_x);
}

static bool	enclosed_up_and_right(UINT map_start, char *world_map[])
{
	UINT	x;
	UINT	y;

	y = map_start;
	x = 0;
	while (world_map[y][x] && world_map[y + 1] != NULL)
	{
		if (world_map[y][x] != WALL && ft_isspace(world_map[y][x]) == false)
			return (false);
		x++;
		if (!world_map[y][x])
		{
			if (ft_strlen(world_map[y]) > ft_strlen(world_map[y + 1]))
				x = trace_next_wall_under(world_map, x, y);
			if (world_map[y + 1][x - 1] != 0)
			{
				y++;
				x--;
			}
		}
	}
	return (true);
}

bool	is_wall_enclosed(UINT map_start, char *world_map[])
{
	if (enclosed_up_and_right(map_start, world_map) == false)
		return (false);
	return (true);
}
