/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   file_validation.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: xvoorvaa <xvoorvaa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/14 17:14:15 by xvoorvaa      #+#    #+#                 */
/*   Updated: 2022/07/20 13:34:52 by xvoorvaa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h" /* t_vars */
#include "error.h" /* Error msg */
#include "libft.h" /* ft_strcmp ft_strndup.c*/

#define WALL '1'

#define NORTH 'N'
#define SOUTH 'S'
#define WEST 'W'
#define EAST 'E'

#define CEILLING 'C'
#define FLOOR 'F'

/*
	Function that checks if the map file has a ".cub"
	extention at the end.
*/
static bool	is_cub_extension(char *argv)
{
	int		i;
	char	**str;

	i = 0;
	str = ft_split(argv, '.');
	if (str == NULL)
		fatal_perror("malloc");
	while (str[i] != NULL)
		i++;
	i--;
	if (ft_strcmp(str[i], "cub") == 0)
	{
		ft_free_array(str);
		return (true);
	}
	ft_free_array(str);
	non_fatal_error(NONVALID_FILE);
	return (false);
}

// static void	init_path_struct(t_path *path_data)
// {
// 	path_data->north = ft_strdup("IMG/Wolfenstein/bluestone.png");
// 	path_data->east = ft_strdup("IMG/Wolfenstein/greystone.png");
// 	path_data->south = ft_strdup("IMG/Wolfenstein/eagle.png");
// 	path_data->west = ft_strdup("IMG/Wolfenstein/wood.png");
// }

static void	process_colors(t_colors *colors)
{
	int 	i;
	char 	**floor_split;
	char	**ceilling_split;

	i = 0;
	//printf("%s\n", colors->floor);
	floor_split = ft_split(colors->floor, ',');
	ceilling_split = ft_split(colors->ceilling, ',');
	while(floor_split[i])
	{
		colors->f_rgb[i] = ft_atoi(floor_split[i]);
		i++;
	}
	i = 0;
	while(ceilling_split[i])
	{
		//printf("[%i]%i - %s\n", i, colors->c_rgb[i], ceilling_split[i]);
		colors->c_rgb[i] = ft_atoi(ceilling_split[i]);
		i++;
	}
}

/*
	ft_strndup is protected by ft_malloc
*/
static int	get_path_data(t_path *path_data, t_colors *colors, t_map *map_data)
{
	int		i;
	int		line;
	char	**array;

	i = 0;
	line = 0;
	array = map_data->world_map;
	while (array[line] && ft_isspace(array[line][i]) != 1)
	{
		if (array[line][i] == NORTH)
			path_data->north = ft_strndup(array[line], 3);
		else if (array[line][i] == SOUTH)
			path_data->south = ft_strndup(array[line], 3);
		else if (array[line][i] == WEST)
			path_data->west = ft_strndup(array[line], 3);
		else if (array[line][i] == EAST)
			path_data->east = ft_strndup(array[line], 3);
		else if (array[line][i] == FLOOR)
			colors->floor = ft_strndup(array[line], 2);
		else if (array[line][i] == CEILLING)
			colors->ceilling = ft_strndup(array[line], 2);
		else
		{
			non_fatal_error(NO_PATH);
			return (ERROR);
		}
		if (array[line][i] == WALL)
		{
			map_data->map_start = line;
			break ;
		}
		line++;
	}
	return (SUCCES);
}

/*
	No error msgs here!
	Do it in the functions that are called here.
*/
bool	is_cub_file_valid(char *cub_file, t_vars *vars)
{
	if (is_cub_extension(cub_file) == false)
		return (false);
	if (read_file(cub_file, vars))
		return (false);
	if (get_path_data(&vars->path_data, &vars->colors, &vars->map_data))
		return (false);
	process_colors(&vars->colors);
	if (check_map(&vars->map_data))
		return (false);
	return (true);
}
