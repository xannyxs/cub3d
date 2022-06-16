/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_wall.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: xvoorvaa <xvoorvaa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/07 17:33:39 by xvoorvaa      #+#    #+#                 */
/*   Updated: 2022/06/16 20:57:11 by xvoorvaa      ########   odam.nl         */
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
int	check_wall(char *world_map[], unsigned int height)
{
	unsigned int	y;

	y = 1;
	if (loop_through_line(world_map[0], WALL) && \
		loop_through_line(world_map[0], ' '))
		return (ERROR);
	while (y < height)
	{
		if (world_map[y][0] != WALL && world_map[y][0] != ' ')
			return (ERROR);
		else if (world_map[y][ft_strlen(world_map[y])] != WALL && \
			world_map[y][ft_strlen(world_map[y])] != ' ' && \
			world_map[y][ft_strlen(world_map[y])] != 0)
			return (ERROR);
		y++;
	}
	if (loop_through_line(world_map[height], WALL) && \
		loop_through_line(world_map[height], ' '))
		return (ERROR);
	if (check_for_holes(world_map, height))
		return (ERROR);
	return (SUCCES);
}
