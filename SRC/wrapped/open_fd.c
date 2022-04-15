/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   open_fd.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: xander <xander@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/15 16:04:15 by xander        #+#    #+#                 */
/*   Updated: 2022/04/15 16:06:45 by xander        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

#include <unistd.h>
#include <fcntl.h>

int	open_fd(char *cub_file)
{
	int	fd;

	fd = open(cub_file, O_RDONLY);
	if (fd < 0)
		fatal_perror(cub_file);
	return (fd);
}
