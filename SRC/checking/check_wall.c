/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_wall.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: xvoorvaa <xvoorvaa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/07 17:33:39 by xvoorvaa      #+#    #+#                 */
/*   Updated: 2022/07/19 19:25:26 by xvoorvaa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "libft.h"

#define WALL '1'
#define EMPTY '0'

/*
	I check if the map has wall on the left & right sides.

	At the end I check if there are any holes in the map,
	and if they are viable.
	It will also pathfind the walls surrounding the map.
*/
int	check_wall(t_map *map_data)
{
	UINT	y;
	char	**map;
	
	y = 1;
	map = map_data->world_map;
	while (y < map_data->height)
	{
		if (map[y][0] != WALL && map[y][0] != ' ')
			return (ERROR);
		else if (map[y][ft_strlen(map[y])] != WALL && \
			map[y][ft_strlen(map[y])] != ' ' && \
			map[y][ft_strlen(map[y])] != 0)
			return (ERROR);
		y++;
	}
	if (check_for_holes(map_data->world_map))
		return (ERROR);
	if (!is_wall_enclosed(map_data->world_map))
		return (ERROR);
	return (SUCCES);
}
