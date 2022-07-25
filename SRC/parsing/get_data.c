/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_data.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: xvoorvaa <xvoorvaa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/25 14:44:05 by xvoorvaa      #+#    #+#                 */
/*   Updated: 2022/07/25 15:21:56 by xvoorvaa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "error.h"

#define WALL '1'

#define NORTH 'N'
#define SOUTH 'S'
#define WEST 'W'
#define EAST 'E'

#define CEILLING 'C'
#define FLOOR 'F'

static int	check_paths(t_path *path_data, t_textures *colors, \
	char *path, int i)
{
	if (path[i] == NORTH)
		path_data->north = ft_strdup(&path[i + 3]);
	else if (path[i] == SOUTH)
		path_data->south = ft_strdup(&path[i + 3]);
	else if (path[i] == WEST)
		path_data->west = ft_strdup(&path[i + 3]);
	else if (path[i] == EAST)
		path_data->east = ft_strdup(&path[i + 3]);
	else if (path[i] == FLOOR)
		colors->floor = ft_strdup(&path[i + 2]);
	else if (path[i] == CEILLING)
		colors->ceiling = ft_strdup(&path[i + 2]);
	else
		return (ERROR);
	return (SUCCES);
}

static UINT	amount_of_space(char *line)
{
	int	len;

	len = 0;
	while (ft_isspace(line[len]) == true)
		len++;
	return (len);
}

/*
	Error handling for file input (parser)
*/
int	get_path_data(t_path *path, t_textures *textures, t_map *map)
{
	int	i;
	int	line;

	line = 0;
	while (map->world_map[line])
	{
		i = amount_of_space(map->world_map[line]);
		if (map->world_map[line][i] == WALL && line != 0)
		{
			map->map_start = line;
			break ;
		}
		if (ft_isnull(map->world_map[line][i]) == true)
		{
			line++;
			continue ;
		}
		if (check_paths(path, textures, map->world_map[line], i) == ERROR)
		{
			non_fatal_error(NO_PATH);
			return (ERROR);
		}
		line++;
	}
	return (SUCCES);
}
