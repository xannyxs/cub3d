/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_player.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: xvoorvaa <xvoorvaa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/07 17:29:46 by xvoorvaa      #+#    #+#                 */
/*   Updated: 2022/06/16 20:50:25 by xvoorvaa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

#define MANY_PLAYERS_ERROR 2

static bool	is_player(char c)
{
	if (c == 'N' || c == 'W' || c == 'E' || c == 'S')
		return (true);
	return (false);
}

static bool	does_player_already_exist(bool player_exists)
{
	if (player_exists == false)
	{
		player_exists = true;
		return (true);
	}
	return (false);
}

int	check_player(t_map map_data)
{
	unsigned int	x;
	unsigned int	y;
	bool			player_exists;

	x = 0;
	y = 1;
	player_exists = false;
	while (y < map_data.height)
	{
		while (map_data.world_map[y][x])
		{
			if (is_player(map_data.world_map[y][x]) == true)
			{
				player_exists = does_player_already_exist(player_exists);
				if (player_exists == false)
					return (MANY_PLAYERS_ERROR);
			}
			x++;
		}
		x = 0;
		y++;
	}
	if (player_exists == true)
		return (SUCCES);
	return (ERROR);
}
