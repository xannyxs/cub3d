/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   file_validation.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: xvoorvaa <xvoorvaa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/14 17:14:15 by xvoorvaa      #+#    #+#                 */
/*   Updated: 2022/07/23 22:27:12 by swofferh      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h> /* ERRNO */
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

/*
	First it turns the RGB string from the parser into a array of ints[3]
	then checks for errors (if negative numbers, if isalpha(), and max 255)
*/
static void	process_colors(t_textures *textures)
{
	int 	i;
	char 	**floor_split;
	char	**ceilling_split;

	i = 0;
	floor_split = ft_split(textures->floor, ',');
	ceilling_split = ft_split(textures->ceilling, ',');
	while(floor_split[i])
	{
		textures->f_rgb[i] = ft_atoi(floor_split[i]);
		if(ft_isdigit(textures->f_rgb[i]) == 0 || textures->f_rgb[i] > 255 || textures->f_rgb[i] < 0)
			//non_fatal_error(WRONG_NUMBER);
			exit(errno);			
		i++;
	}
	i = 0;
	while(ceilling_split[i])
	{
		textures->c_rgb[i] = ft_atoi(ceilling_split[i]);
		printf("%i(%s)\n", textures->c_rgb[i], ceilling_split[i]);
		if (ft_isdigit(textures->c_rgb[i]) == 0 || textures->c_rgb[i] < 0 || textures->c_rgb[i] < 0)
			//non_fatal_error(WRONG_NUMBER);
			exit(errno);
		i++;
	}
}

/*
	ft_strndup is protected by ft_malloc
*/
static int	get_path_data(t_path *path_data, t_textures *textures, t_map *map_data)
{
	int		i;
	int		line;
	char	**array;

	line = 0;
	(void)textures;
	array = map_data->world_map;
	while (array[line])
	{
		//printf("%i>", line);
		i = 0;
		while((int)array[line][i] > 0 && (int)array[line][i] <= 32)
		{
			//printf("[%i]", array[line][i]);
			if ((int)array[line][i] >= 46)
				break;
			i++;
		}
		//printf("[%c]%i\n",array[line][i], i);
		if (array[line][i] == WALL)
		{
			map_data->map_start = line;
			break ;
		}
		if (array[line][i] == '\0')
		{
			line++;
			continue ;
		}
		else if (array[line][i] == NORTH)
			path_data->north = ft_strdup(&array[line][i + 3]);
		else if (array[line][i] == SOUTH)
			path_data->south = ft_strdup(&array[line][i + 3]);
		else if (array[line][i] == WEST)
			path_data->west = ft_strdup(&array[line][i + 3]);
		else if (array[line][i] == EAST)
			path_data->east = ft_strdup(&array[line][i + 3]);
		else if (array[line][i] == FLOOR)
			textures->floor = ft_strdup(&array[line][i + 2]);
		else if (array[line][i] == CEILLING)
			textures->ceilling = ft_strdup(&array[line][i + 2]);
		else
		{
			//printf("\nerror[%i][%i] int=%i char=%c%c\n", line, i, array[line][i], array[line][i], array[line][i+1]);
			non_fatal_error(NO_PATH);
			return (ERROR);
		}
		//printf(">%s\n", path_data->south);
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
	if (get_path_data(&vars->path_data, &vars->textures, &vars->map_data))
		return (false);
	process_colors(&vars->textures);
	if (check_map(&vars->map_data))
		return (false);
	return (true);
}
