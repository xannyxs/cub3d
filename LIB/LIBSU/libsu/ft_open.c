/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_open.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: xander <xander@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/15 16:04:15 by xander        #+#    #+#                 */
/*   Updated: 2022/07/22 13:51:38 by swofferh      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h" /* ft_strlen */

#include <unistd.h> /* write */
#include <stdio.h> /* perror */
#include <errno.h> /* ERRNO */
#include <stdlib.h> /* exit */
#include <fcntl.h>

#define RED "\033[0;31m"
#define HYEL "\e[0;93m"
#define RESET "\e[0m"

static void	fatal_perror(char *msg)
{
	write(STDERR_FILENO, HYEL, 8);
	perror(msg);
	write(STDERR_FILENO, RESET, 5);
	exit(errno);
}

int	ft_open(char *file)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		fatal_perror(file);
	return (fd);
}
