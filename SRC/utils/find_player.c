/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   find_player.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: xvoorvaa <xvoorvaa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/10 16:39:19 by xvoorvaa      #+#    #+#                 */
/*   Updated: 2022/06/16 18:04:30 by xvoorvaa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
					vars->data.pos.x = x + 0.5;
					vars->data.pos.y = y + 0.5;
					vars->map_data.world_map[y][x] = '0';
					return ;
				}
			x++;
		}
		x = 0;
		y++;
	}
}