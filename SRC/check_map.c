/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_map.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: xvoorvaa <xvoorvaa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/15 16:28:08 by xvoorvaa      #+#    #+#                 */
/*   Updated: 2022/04/16 21:49:39 by xvoorvaa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "error.h"

#include <stdio.h>
#include <unistd.h>

#define WALL '1'
#define EMPTY '0'

static int	loop_through_line(char *map_line, char object)
{
	unsigned int	x;

	x = 0;
	while (map_line[x])
	{
		if (map_line[x] != object)
			return (ERROR);
		x++;
	}
	return (SUCCES);
}

static int	check_wall(t_map map_data)
{
	unsigned int	x;
	unsigned int	y;

	x = 0;
	y = 1;
	if (loop_through_line(map_data.map_grid[0], WALL))
		return (ERROR);
	while (y < map_data.height)
	{
		if (map_data.map_grid[y][0] != WALL)
			return (ERROR);
		else if (map_data.map_grid[y][map_data.width] != WALL)
			return (ERROR);
		y++;
	}
	if (loop_through_line(map_data.map_grid[map_data.height], WALL))
		return (ERROR);
	return (SUCCES);
}

static int	check_player(t_map map_data)
{
	unsigned int	x;
	unsigned int	y;

	x = 0;
	y = 1;
	while (y < map_data.height)
	{
		while (map_data.map_grid[y][x])
		{
			if (map_data.map_grid[y][x] == 'N' || \
				map_data.map_grid[y][x] == 'E' || \
				map_data.map_grid[y][x] == 'S' ||\
				map_data.map_grid[y][x] == 'W')
				return (SUCCES);
			x++;
		}
		x = 0;
		y++;
	}
	return (ERROR);
}

static int	check_unknown(t_map map_data)
{
	unsigned int	x;
	unsigned int	y;

	x = 0;
	y = 1;
	while (y < map_data.height)
	{
		while (map_data.map_grid[y][x])
		{
			if (map_data.map_grid[y][x] != EMPTY && \
				map_data.map_grid[y][x] != WALL && \
				map_data.map_grid[y][x] != 'N' && \
				map_data.map_grid[y][x] != 'E' && \
				map_data.map_grid[y][x] != 'S' && \
				map_data.map_grid[y][x] != 'W')
				return (ERROR);
			x++;
		}
		x = 0;
		y++;
	}
	return (SUCCES);
}

static void	get_map_size(t_map *map_data)
{
	int	x;
	int	y;

	y = 0;
	while (map_data->map_grid[y] != NULL)
	{
		x = 0;
		while (map_data->map_grid[y][x] != '\0')
			x++;
		y++;
	}
	map_data->height = y - 1;
	map_data->width = x - 1;
}

int	check_map(t_map *map_data)
{
	get_map_size(map_data);
	if (check_wall(*map_data))
	{
		non_fatal_error(MISSING_WALL);
		return (ERROR);
	}
	if (check_player(*map_data))
	{
		non_fatal_error(MISSING_PLAYER);
		return (ERROR);
	}
	if (check_unknown(*map_data))
	{
		non_fatal_error(UNKNOWN_CHAR);
		return (ERROR);
	}
	return (SUCCES);
}
