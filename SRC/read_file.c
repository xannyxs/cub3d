/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   read_file.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: xvoorvaa <xvoorvaa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/14 18:25:30 by xvoorvaa      #+#    #+#                 */
/*   Updated: 2022/04/14 19:25:21 by xvoorvaa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

#include <fcntl.h> /* open */
#include <unistd.h> /* close */
#include <stdlib.h>

#include <stdio.h>

static int	get_line(t_vars *vars, int fd)
{
	int		i;
	char	*line;
	char	**all_lines;

	(void) vars;
	i = 0;
	all_lines = malloc(sizeof(char *) * (4));
	while (get_next_line(fd, &line) > 0)
	{
		all_lines[i] = line;
		printf("line %d | %s\n", i, all_lines[i]);
		i++;
		free(line);
	}
	free(line);
	return (SUCCES);
}

int	read_file(char *cub_file, t_vars *vars)
{
	int		fd;

	(void) vars;
	fd = open(cub_file, O_RDONLY);
	if (fd < 0)
	{
		fatal_perror(cub_file);
		return (ERROR);
	}
	if (get_line(vars, fd))
		return (ERROR);
	// if (check_map(vars))
	// 	return (ERROR);
	close(fd);
	return (SUCCES);
}
