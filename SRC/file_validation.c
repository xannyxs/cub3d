/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   file_validation.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: xvoorvaa <xvoorvaa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/14 17:14:15 by xvoorvaa      #+#    #+#                 */
/*   Updated: 2022/04/14 18:35:57 by xvoorvaa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "error.h" /* Error msg */
#include "cub3d.h" /* t_vars */
#include "libft.h" /* ft_strcmp */

#include <stddef.h> /* free */

static bool	is_cub_extension(char *argv)
{
	int		i;
	char	**str;

	i = 0;
	str = ft_split(argv, '.');
	if (str == NULL)
	{
		fatal_perror("malloc");
		return (false);
	}
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

/*	No error msgs here!
**	Do it in the functions that are called here
*/
bool	is_cub_file_valid(char *argv[], t_vars *vars)
{
	if (is_cub_extension(argv[1]) == false)
		return (false);
	if (read_file(argv[1], vars))
		return (false);
	return (true);
}
