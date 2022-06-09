/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_wall.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: xvoorvaa <xvoorvaa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/07 17:33:39 by xvoorvaa      #+#    #+#                 */
/*   Updated: 2022/06/09 15:10:17 by xvoorvaa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "libft.h"

#define WALL '1'
#define EMPTY '0'

/*
	Made a "char **temp_world_map" because of norm...

	I first check if the first row is OK,
	then I check if the map has wall on the side.
	At last, I check if the last row is OK.

	At the end I check if there are any holes in the map,
	and if they are viable.
*/
int	check_wall(t_map map_data)
{
	unsigned int	y;
	char			**temp_world_map;

	y = 1;
	temp_world_map = map_data.world_map;
	if (loop_through_line(temp_world_map[0], WALL) && \
		loop_through_line(temp_world_map[0], ' '))
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
	if (loop_through_line(temp_world_map[map_data.height], WALL) && \
		loop_through_line(temp_world_map[map_data.height], ' '))
		return (ERROR);
	if (check_for_holes(map_data))
		return (ERROR);
	return (SUCCES);
}