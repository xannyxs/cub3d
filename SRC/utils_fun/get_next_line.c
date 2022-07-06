/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: xvoorvaa <xvoorvaa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/27 13:56:35 by xvoorvaa      #+#    #+#                 */
/*   Updated: 2022/04/14 18:59:10 by xvoorvaa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>
#include <stdio.h>

#define BUFFER_SIZE 5

static size_t	ft_strline(char const *str)
{
	size_t	len;

	len = 0;
	while (str[len] != '\n')
		len++;
	return (len);
}

static int	emptyfile(char **line, int bytes_read, char *twin)
{
	if (bytes_read < 0)
		return (-1);
	*line = ft_strdup("");
	if (!twin && bytes_read > 0)
	{
		free(twin);
		return (-1);
	}
	if (!*line)
		free(line);
	return (0);
}

static char	*to_line(char **line, char *twin)
{
	char	*temp;

	if (ft_strchr(twin, '\n') != NULL)
	{
		*line = ft_substr(twin, 0, ft_strline(twin));
		temp = ft_strdup(ft_strchr(twin, '\n') + 1);
		free(twin);
		twin = temp;
		return (twin);
	}
	*line = twin;
	twin = NULL;
	return (twin);
}

int	read_line(int fd, char **line, int bytes_read, char buff[BUFFER_SIZE + 1])
{
	static char	*twin;

	bytes_read = read(fd, buff, BUFFER_SIZE);
	if (bytes_read <= 0 && !twin)
		return (emptyfile(line, bytes_read, twin));
	while (bytes_read > 0)
	{
		buff[bytes_read] = '\0';
		if (twin == NULL)
			twin = ft_strdup(buff);
		else
			twin = ft_strjoin_free(twin, buff);
		if (ft_strchr(twin, '\n'))
		{
			twin = to_line(line, twin);
			return (1);
		}
		bytes_read = read(fd, buff, BUFFER_SIZE);
	}
	if (twin == NULL)
		emptyfile(line, bytes_read, twin);
	twin = to_line(line, twin);
	if (twin != NULL)
		return (1);
	return (0);
}

int	get_next_line(int fd, char **line)
{
	int		bytes_read;
	char	buff[BUFFER_SIZE + 1];

	bytes_read = 0;
	if (!line)
		return (-1);
	if (BUFFER_SIZE <= 0 || fd < 0 || fd > 1024)
	{
		*line = NULL;
		return (-1);
	}
	return (read_line(fd, line, bytes_read, buff));
}
