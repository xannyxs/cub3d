/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_map.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: xvoorvaa <xvoorvaa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/15 16:28:08 by xvoorvaa      #+#    #+#                 */
/*   Updated: 2022/06/06 20:31:44 by xvoorvaa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "libft.h"
#include "error.h"

#define WALL '1'
#define EMPTY '0'

static int	check_wall(t_map map_data)
{
	unsigned int	x;
	unsigned int	y;
	char			**temp_world_map;

	x = 0;
	y = 1;
	temp_world_map = map_data.world_map;
	if (loop_through_line(temp_world_map[0], WALL))
		return (ERROR);
	while (y < map_data.height)
	{
		if (temp_world_map[y][0] != WALL && temp_world_map[y][0] != ' ')
			return (ERROR);
		else if (temp_world_map[y][ft_strlen(temp_world_map[y])] != WALL && \
			temp_world_map[y][ft_strlen(temp_world_map[y])] != ' ' && \
			temp_world_map[y][ft_strlen(temp_world_map[y])] != 0)
			return (ERROR);
		y++;
	}
	if (loop_through_line(temp_world_map[map_data.height], WALL))
		return (ERROR);
	if (check_for_holes(map_data))
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
		while (map_data.world_map[y][x])
		{
			if (map_data.world_map[y][x] == 'N' || \
				map_data.world_map[y][x] == 'E' || \
				map_data.world_map[y][x] == 'S' || \
				map_data.world_map[y][x] == 'W')
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

static void	get_map_size(t_map *map_data)
{
	int	x;
	int	y;

	y = 0;
	map_data->width = 0;
	while (map_data->world_map[y] != NULL)
	{
		x = 0;
		while (map_data->world_map[y][x] != '\0')
			x++;
		if ((int)map_data->width < x - 1)
			map_data->width = x - 1;
		y++;
	}
	map_data->height = y - 1;
}

int	check_map(t_map *map_data)
{
	get_map_size(map_data);
	if (check_unknown(*map_data))
	{
		non_fatal_error(UNKNOWN_CHAR);
		return (ERROR);
	}
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
	return (SUCCES);
}
