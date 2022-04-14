/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   read_file.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: xvoorvaa <xvoorvaa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/14 18:25:30 by xvoorvaa      #+#    #+#                 */
/*   Updated: 2022/04/14 18:37:18 by xvoorvaa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

#include <fcntl.h> /* open */
#include <unistd.h> /* close */
#include <stddef.h>

int	read_file(char *cub_file, t_vars *vars)
{
	int		fd;
	char	*line;

	line = NULL;
	(void) vars;
	fd = open(cub_file, O_RDONLY);
	if (fd < 0)
	{
		fatal_perror(cub_file);
		return (ERROR);
	}
	// if (get_line(fd, line, vars))
	// 	return (ERROR);
	// if (check_map(vars))
	// 	return (ERROR);
	close(fd);
	return (SUCCES);
}
