/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_malloc.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: xvoorvaa <xvoorvaa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/16 21:29:56 by xvoorvaa      #+#    #+#                 */
/*   Updated: 2022/07/15 17:34:54 by xvoorvaa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h> /* write */
#include <stdio.h> /* perror */
#include <errno.h> /* ERRNO */
#include <stdlib.h> /* exit */

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

void	*ft_malloc(size_t size)
{
	void	*ptr;

	ptr = malloc(size);
	if (!ptr)
		fatal_perror("malloc");
	return (ptr);
}
