/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_map.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: xvoorvaa <xvoorvaa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/15 16:28:08 by xvoorvaa      #+#    #+#                 */
/*   Updated: 2022/07/14 11:25:28 by swofferh      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "error.h"

#define WALL '1'
#define EMPTY '0'

#define MANY_PLAYERS_ERROR 2

static void	get_map_size(t_map *map_data)
{
	int	x;
	int	y;

	map_data->width = 0;
	map_data->height = -1;
	y = map_data->map_start;
	while (map_data->world_map[y] != NULL)
	{
		x = 0;
		while (map_data->world_map[y][x] != '\0')
			x++;
		if ((int)map_data->width < x - 1)
			map_data->width = x - 1;
		y++;
		map_data->height++;
	}
}

/*
	I first check for unknown chars,
	then I check if the map is correctly surrounded by walls.
	Last but not least, I check if I only have one player on the map.

	I check for a player twice, because of the error code. Could be much better.
*/
int	check_map(t_map *map_data)
{
	get_map_size(map_data);
	if (check_unknown(*map_data))
	{
		non_fatal_error(UNKNOWN_CHAR);
		return (ERROR);
	}
	if (check_wall(map_data))
	{
		non_fatal_error(MISSING_WALL);
		return (ERROR);
	}
	if (check_player(*map_data) == ERROR)
	{
		non_fatal_error(MISSING_PLAYER);
		return (ERROR);
	}
	else if (check_player(*map_data) == MANY_PLAYERS_ERROR)
	{
		non_fatal_error(TOO_MANY_PLAYERS);
		return (ERROR);
	}
	return (SUCCES);
}
