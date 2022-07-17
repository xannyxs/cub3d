/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_wall_utils.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: xvoorvaa <xvoorvaa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/06 12:09:47 by xvoorvaa      #+#    #+#                 */
/*   Updated: 2022/07/17 13:11:01 by xvoorvaa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "libft.h" /* ft_strlen */

#define WALL '1'
#define EMPTY ' '

static bool	is_empty_or_wall(char c)
{
	if (c == EMPTY || c == WALL || c == 0)
		return (true);
	return (false);
}

/*
	Checks 3 chars above, middle and under a character
	that should be surrounded.
*/
static int	surround_loop(char *world_line, int x, int len_line)
{
	int	max_x;

	max_x = x + 1;
	if (x >= 1)
		x = x - 1;
	while (x <= len_line && x <= max_x)
	{
		if (is_empty_or_wall(world_line[x]) == false)
			return (ERROR);
		x++;
	}
	return (SUCCES);
}

static int	check_surrounding(char **world_map, int x, int y)
{
	if (surround_loop(world_map[y - 1], x, ft_strlen(world_map[y - 1])))
		return (ERROR);
	if (surround_loop(world_map[y], x, ft_strlen(world_map[y])))
		return (ERROR);
	if (surround_loop(world_map[y + 1], x, ft_strlen(world_map[y + 1])))
		return (ERROR);
	return (SUCCES);
}

/*
	Check if there are any spaces in the map.
	If so, check if it is surrounded by other spaces or walls.
	This is kind of a mass, because of norm...
*/
bool	check_for_holes(char *world_map[])
{
	UINT	x;
	UINT	y;

	y = 0;
	while (world_map[y])
	{
		x = 0;
		while (x <= ft_strlen(world_map[y]))
		{
			if (world_map[y][x] == WALL && world_map[y][x + 1] == '\0')
			{
				if (ft_strlen(world_map[y]) > ft_strlen(world_map[y + 1]))
				{
					printf("%s\n", world_map[y]);
					printf("%s\n", world_map[y + 1]);
					printf("%c\n", world_map[y + 1][ft_strlen(world_map[y + 1]) - 1]);
					if (world_map[y + 1][ft_strlen(world_map[y + 1]) - 1] == WALL)
						break ;
					else
						return (ERROR);
				}
				else if (world_map[y + 1][x] == WALL)
					break ;
				else
					return (ERROR);
			}
			if (world_map[y][x] == EMPTY)
			{
				if (check_surrounding(world_map, x, y) == ERROR)
					return (true);
			}
			x++;
		}
		y++;
	}
	return (false);
}

int	loop_through_line(char *map_line, char object)
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
