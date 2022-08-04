/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_data.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: xvoorvaa <xvoorvaa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/25 14:44:05 by xvoorvaa      #+#    #+#                 */
/*   Updated: 2022/08/04 14:40:10 by swofferh      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "error.h"

#define WALL '1'

/*
	Parsing 'WE' 'NO' 'EA' 'SO' input in files, also 'F' 'C'
*/
static int	check_paths(t_path *data, t_textures *colors, char *path, int i)
{
	if (path[i] == 'N' && path[i + 1] == 'O' && data->north == NULL)
		data->north = ft_strdup(&path[i + 3]);
	else if (path[i] == 'S' && path[i + 1] == 'O' && data->south == NULL)
		data->south = ft_strdup(&path[i + 3]);
	else if (path[i] == 'W' && path[i + 1] == 'E' && data->west == NULL)
		data->west = ft_strdup(&path[i + 3]);
	else if (path[i] == 'E' && path[i + 1] == 'A' && data->east == NULL)
		data->east = ft_strdup(&path[i + 3]);
	else if (path[i] == 'F' && path[i + 1] == ' ' && colors->floor == NULL)
		colors->floor = ft_strdup(&path[i + 2]);
	else if (path[i] == 'C' && path[i + 1] == ' ' && colors->ceiling == NULL)
		colors->ceiling = ft_strdup(&path[i + 2]);
	else
		return (ERROR);
	return (SUCCES);
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
		i = ft_lenspace(map->world_map[line]);
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
