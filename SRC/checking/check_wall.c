/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_wall.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: xvoorvaa <xvoorvaa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/07 17:33:39 by xvoorvaa      #+#    #+#                 */
/*   Updated: 2022/07/17 14:27:43 by xvoorvaa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "libft.h"

#define WALL '1'
#define EMPTY '0'

/*
	I first check if the first row is OK,
	then I check if the map has wall on the side.
	At last, I check if the last row is OK.

	At the end I check if there are any holes in the map,
	and if they are viable.
*/
int	check_wall(t_map *map_data)
{
	unsigned int	y;
	char 			**map;
	
	map = map_data->world_map;
	y = 1;
	if (loop_through_line(map[map_data->map_start], WALL) && \
		loop_through_line(map[map_data->map_start], ' '))
		return (ERROR);
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
	if (loop_through_line(map[map_data->height], WALL) && \
		loop_through_line(map[map_data->height], ' '))
		return (ERROR);
	if (check_for_holes(map_data->world_map))
		return (ERROR);
	if (!is_wall_enclosed(map_data->world_map))
		return (ERROR);
	return (SUCCES);
}
