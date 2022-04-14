/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   read_file.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: xvoorvaa <xvoorvaa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/14 18:25:30 by xvoorvaa      #+#    #+#                 */
/*   Updated: 2022/04/14 19:17:39 by xvoorvaa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

#include <fcntl.h> /* open */
#include <unistd.h> /* close */
#include <stdlib.h>

static int	get_line(t_vars *vars, int fd)
{
	char	*line;

	(void) vars;
	while (get_next_line(fd, &line) > 0)
		write(1, "CHECK\n", 7);
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
