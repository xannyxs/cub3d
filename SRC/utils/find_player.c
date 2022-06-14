/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   find_player.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: xvoorvaa <xvoorvaa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/10 16:39:19 by xvoorvaa      #+#    #+#                 */
/*   Updated: 2022/06/14 16:41:22 by xvoorvaa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "libft.h"

#include <stdio.h>

/*
	Kinda already doing this, can be better optimized.
	Check: check_player().
*/
void	find_player(t_vars *vars)
{
	unsigned int	x;
	unsigned int	y;

	x = 0;
	y = 0;
	while (vars->map_data.world_map[y] != NULL)
	{
		while (vars->map_data.world_map[y][x] != '\0')
		{
			if (vars->map_data.world_map[y][x] == 'N' ||
				vars->map_data.world_map[y][x] == 'W' ||
				vars->map_data.world_map[y][x] == 'S' ||
				vars->map_data.world_map[y][x] == 'O')
				{
					vars->data.pos_x = x + 0.5;
					vars->data.pos_y = y + 0.5;
					return ;
				}
			x++;
		}
		x = 0;
		y++;
	}
}