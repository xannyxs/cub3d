/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   file_validation.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: xvoorvaa <xvoorvaa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/14 17:14:15 by xvoorvaa      #+#    #+#                 */
/*   Updated: 2022/07/19 19:55:12 by swofferh      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h" /* t_vars */
#include "error.h" /* Error msg */
#include "libft.h" /* ft_strcmp ft_strndup.c*/

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

/*
	ft_strndup is protected by ft_malloc
*/
static void	get_path_data(t_path *path_data, t_colors *colors, t_map *map_data)
{
	int		i;
	int		line;
	char	**array;
	
	i = 0;
	line = 0;
	array = map_data->world_map;
	while (array[line] && ft_isspace(array[line][i]) != 1)
	{
		if (array[line][i] == 'N')
			path_data->north = ft_strndup(array[line], 3);
		else if (array[line][i] == 'S')
			path_data->south = ft_strndup(array[line], 3);
		else if (array[line][i] == 'W')
			path_data->west = ft_strndup(array[line], 3);
		else if (array[line][i] == 'E')
			path_data->east = ft_strndup(array[line], 3);
		else if (array[line][i] == 'F')
			colors->floor = ft_strndup(array[line], 2);
		else if (array[line][i] == 'C')
			colors->ceilling = ft_strndup(array[line], 2);
		else
			non_fatal_error("File needs paths and colours");
		if (array[line][i] == '1')
		{
			map_data->map_start = line;
			break ;
		}
		line++;
	}
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
	get_path_data(&vars->path_data, &vars->colors, &vars->map_data);
	if (check_map(&vars->map_data))
		return (false);
	return (true);
}