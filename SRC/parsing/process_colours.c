/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   process_colours.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: xvoorvaa <xvoorvaa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/25 15:08:39 by xvoorvaa      #+#    #+#                 */
/*   Updated: 2022/07/25 16:56:41 by xvoorvaa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "error.h"

#include <errno.h> /* Errno */

static void	process_floor(t_textures *textures)
{
	int		i;
	char	**floor_split;

	i = 0;
	floor_split = ft_split(textures->floor, ',');
	while (floor_split[i])
	{
		textures->f_rgb[i] = ft_strtoi(floor_split[i]);
		if (!(textures->f_rgb[i] <= 255 && textures->f_rgb[i] >= 0) || \
			errno == EINVAL)
		{
			non_fatal_error(WRONG_NUMBER);
			exit(ERROR);
		}
		i++;
	}
	ft_free_array(floor_split);
	free(textures->floor);
	if (i != 3)
	{
		non_fatal_error(RBG_ERROR);
		exit (ERROR);
	}
}

static void	process_ceiling(t_textures *textures)
{
	int		i;
	char	**ceiling_split;

	i = 0;
	ceiling_split = ft_split(textures->ceiling, ',');
	while (ceiling_split[i])
	{
		textures->c_rgb[i] = ft_strtoi(ceiling_split[i]);
		if (!(textures->c_rgb[i] <= 255 && textures->c_rgb[i] >= 0) || \
			errno == EINVAL)
		{
			non_fatal_error(WRONG_NUMBER);
			exit(ERROR);
		}
		i++;
	}
	ft_free_array(ceiling_split);
	free(textures->ceiling);
	if (i != 3)
	{
		non_fatal_error(RBG_ERROR);
		exit (ERROR);
	}
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
