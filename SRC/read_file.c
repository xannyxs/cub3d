/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   read_file.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: xvoorvaa <xvoorvaa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/14 18:25:30 by xvoorvaa      #+#    #+#                 */
/*   Updated: 2022/04/15 16:04:20 by xander        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "error.h"

#include <fcntl.h> /* open */
#include <unistd.h> /* close */
#include <stdlib.h> /* malloc */

#include <stdio.h>

static size_t	count_file_lines(char *cub_file)
{
	int		fd;
	char	*line;
	size_t	amount_of_lines;

	amount_of_lines = 0;
	fd = open_fd(cub_file);
	while (get_next_line(fd, &line) > 0)
	{
		amount_of_lines++;
		free(line);
	}
	if (!amount_of_lines)
	{
		non_fatal_error(EMPTY_FILE);
		return (amount_of_lines);
	}
	amount_of_lines++;
	free(line);
	close(fd);
	return (amount_of_lines);
}

/*
**	This function is not really safe.
**	Please take a good look at it.
*/
static int	get_lines(char *cub_file, t_vars *vars, size_t amount_of_lines)
{
	int		i;
	int		fd;
	char	*line;

	i = 0;
	fd = open_fd(cub_file);
	vars->map = malloc(sizeof(char *) * amount_of_lines);
	if (!vars->map)
		fatal_perror("malloc");
	while (get_next_line(fd, &line) > 0)
	{
		vars->map[i] = line;
		i++;
		free(line);
	}
	if (!vars->map)
	{
		non_fatal_error(GNL_ERROR);
		return (ERROR);
	}
	vars->map[i] = line;
	free(line);
	close(fd);
	return (SUCCES);
}

int	read_file(char *cub_file, t_vars *vars)
{
	size_t	amount_of_lines;

	(void) vars;
	amount_of_lines = count_file_lines(cub_file);
	if (amount_of_lines <= 0)
		return (ERROR);
	if (get_lines(cub_file, vars, amount_of_lines))
		return (ERROR);
	// if (check_map(vars))
	// 	return (ERROR);
	return (SUCCES);
}
