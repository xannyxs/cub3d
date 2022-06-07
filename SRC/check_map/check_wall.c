/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_wall.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: xvoorvaa <xvoorvaa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/07 17:33:39 by xvoorvaa      #+#    #+#                 */
/*   Updated: 2022/06/07 17:35:20 by xvoorvaa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "libft.h"

#define WALL '1'
#define EMPTY '0'

/*
	Made it a temp_world_map because of norm...
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