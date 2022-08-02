/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   file_validation.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: xvoorvaa <xvoorvaa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/14 17:14:15 by xvoorvaa      #+#    #+#                 */
/*   Updated: 2022/08/02 17:59:28 by swofferh      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h" /* t_vars */
#include "error.h" /* Error msg */
#include "libft.h" /* ft_strcmp */

/*
	Function that checks if the map file has a ".cub"
	extension at the end.

*/
static bool	is_cub_extension(char *cub_file)
{
	int		i;
	char	**str;

	i = 0;
	str = ft_split(cub_file, '.');
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

static bool	file_has_name(char *cub_file)
{
	char	*temp;

	temp = cub_file;
	while (ft_strchr(temp, '/') != NULL)
		temp = ft_strchr(temp, '/') + 1;
	if (!temp && ft_strlen(cub_file) - 4 == 0)
		return (false);
	else if (ft_strlen(temp) - 4 == 0)
		return (false);
	return (true);
}

/* 
	Checks for spaces before paths
*/
static void	process_paths(t_vars *vars)
{
	printf("%s\n", vars->path_data.north);
	ft_nospace(vars->path_data.north);
	printf("%s\n", vars->path_data.north);
	ft_nospace(vars->path_data.south);
	ft_nospace(vars->path_data.east);
	ft_nospace(vars->path_data.west);
}

static void	process_data(t_vars *vars)
{
	process_colors(&vars->textures);
	process_paths(vars);
}

/*
	No error msgs here!
	Do it in the functions that are called here.
*/
bool	is_cub_file_valid(char *cub_file, t_vars *vars)
{
	if (is_cub_extension(cub_file) == false)
		return (false);
	if (file_has_name(cub_file) == false)
		return (false);
	if (read_file(cub_file, vars))
		return (false);
	if (get_path_data(&vars->path_data, &vars->textures, &vars->map_data))
	{
		ft_free_array(vars->map_data.world_map);
		return (false);
	}
	process_data(vars);
	if (check_map(&vars->map_data))
	{
		ft_free_array(vars->map_data.world_map);
		return (false);
	}
	return (true);
}
