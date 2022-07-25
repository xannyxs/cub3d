/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_data.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: xvoorvaa <xvoorvaa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/25 14:44:05 by xvoorvaa      #+#    #+#                 */
/*   Updated: 2022/07/25 14:56:05 by xvoorvaa      ########   odam.nl         */
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

static void	process_floor(t_textures *textures)
{
	int		i;
	char	**floor_split;

	i = 0;
	floor_split = ft_split(textures->floor, ',');
	while (floor_split[i])
	{
		textures->f_rgb[i] = ft_atoi(floor_split[i]);
		if (textures->f_rgb[i] > 255 || textures->f_rgb[i] < 0)
			fatal_perror(WRONG_NUMBER);
		i++;
	}
	ft_free_array(floor_split);
	free(textures->floor);
}

static void	process_ceiling(t_textures *textures)
{
	int		i;
	char	**ceiling_split;

	i = 0;
	ceiling_split = ft_split(textures->ceiling, ',');
	while (ceiling_split[i])
	{
		textures->c_rgb[i] = ft_atoi(ceiling_split[i]);
		if (textures->c_rgb[i] > 255 || textures->c_rgb[i] < 0)
			fatal_perror(WRONG_NUMBER);
		i++;
	}
	ft_free_array(ceiling_split);
	free(textures->ceiling);
}

/*
	First it turns the RGB string from the parser into a array of ints[3]
	then checks for errors (if negative numbers, if isalpha(), and max 255)
*/
void	process_colors(t_textures *textures)
{
	process_floor(textures);
	process_ceiling(textures);
}

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
		i = 0;
		while (ft_isspace(map->world_map[line][i]) == true)
			i++;
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
