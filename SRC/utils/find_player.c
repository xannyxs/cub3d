/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   find_player.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: xvoorvaa <xvoorvaa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/10 16:39:19 by xvoorvaa      #+#    #+#                 */
/*   Updated: 2022/07/19 20:38:31 by xvoorvaa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
	Kinda already doing this, can be better optimized.
	Check: check_player().
*/
void	find_player(t_vars *vars)
{
	UINT	x;
	UINT	y;

	y = vars->map_data.map_start;
	while (vars->map_data.world_map[y] != NULL)
	{
		x = 0;
		while (vars->map_data.world_map[y][x] != '\0')
		{
			if (vars->map_data.world_map[y][x] == 'N' ||
				vars->map_data.world_map[y][x] == 'W' ||
				vars->map_data.world_map[y][x] == 'S' ||
				vars->map_data.world_map[y][x] == 'E')
			{
				vars->data.pos_x = x + 0.5;
				vars->data.pos_y = y + 0.5;
				vars->data.player_char = vars->map_data.world_map[y][x];
				vars->map_data.world_map[y][x] = '0';
				return ;
			}
			x++;
		}
		y++;
	}
}
