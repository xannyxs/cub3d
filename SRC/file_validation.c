/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   file_validation.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: xvoorvaa <xvoorvaa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/14 17:14:15 by xvoorvaa      #+#    #+#                 */
/*   Updated: 2022/07/04 11:14:00 by sofferha      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/*                                                                            */
/*                                                        ::::::::            */
/*   file_validation.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: xvoorvaa <xvoorvaa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/14 17:14:15 by xvoorvaa      #+#    #+#                 */
/*   Updated: 2022/07/03 21:58:29 by sofferha      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "error.h" /* Error msg */
#include "cub3d.h" /* t_vars */
#include "libft.h" /* ft_strcmp ft_strndup.c*/

#include <stddef.h> /* free */
#include <stdio.h> 

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

// static void	new_world_map(char **array, int i)
// {
// 	int j;
// 	char **map;
	
// 	j = 0;
// 	map = ft_split(array[i], '\n');
// 	//printf("[%i]%s\n", i, array[i]);
// 	while (map[j])
// 	{
// 		printf("[%i]%s\n", j, map[j]);
// 		//map_data->world_map[j] = map[j];
// 		j++;
// 	}
// 	// for (int x = 0; map[x]; x++)
// 	//   	printf("[%i]%s\n", x, map[x]);
// }

static int	get_path_data(t_path *path_data, t_map *map_data)
{
	int i;
	int line;
	char **array;
	
	i = 0;
	line = 0;
	
	array = map_data->file_array;
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
			path_data->floor = ft_strndup(array[line], 2);
		else if (array[line][i] == CEILLING)
			path_data->ceilling = ft_strndup(array[line], 2);
		printf("[%i]%s\n", line, array[line]);
		// if (array[line][i] == WALL)
		// 	new_world_map(array + i, line);
		line++;
	}
	return(SUCCES);
}

int	check_path(t_vars *vars)
{
	if(get_path_data(&vars->path_data, &vars->map_data))
		return(ERROR);
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
	if (check_path(vars))
		return(false);
	if (check_map(&vars->map_data))
		return (false);
	return (true);
}
