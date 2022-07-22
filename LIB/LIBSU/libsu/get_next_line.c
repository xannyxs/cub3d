/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: swofferh <swofferh@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/08 21:54:03 by swofferh      #+#    #+#                 */
/*   Updated: 2022/07/20 13:38:01 by xvoorvaa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 32
#endif

typedef enum e_state
{
	ONE_LINE = 1,
	END_FILE = 0,
	ERROR = -1,
	LOOP = 2
}	t_state;

static char	*copy_buffer(char *old, char *new, int n)
{
	char	*next;
	int		len;

	if (old == NULL)
	{
		next = (char *)ft_malloc(sizeof(char) * (n + 1));
		if (next == NULL)
			return (NULL);
		ft_strncpy(next, new, n);
	}
	else
	{
		len = ft_strclen(old, '\0');
		next = (char *)ft_malloc(sizeof(char) * (len + n + 1));
		if (next == NULL)
			return (NULL);
		ft_strncpy(next, old, len);
		free(old);
		ft_strncpy(next + len, new, n);
	}
	return (next);
}

static t_state	read_line(int fd, char *buffer, char **out, int *size)
{
	ssize_t	ret;
	int		i;

	if (*size == 0)
	{
		ret = read(fd, buffer, BUFFER_SIZE);
		if (ret == END_FILE || ret == ERROR)
			return (ret);
		buffer[ret] = '\0';
		*size = ret;
	}
	i = ft_strclen(buffer, '\n');
	*out = copy_buffer(*out, buffer, i);
	if (*out == NULL)
		return (ERROR);
	if (i < *size)
	{
		*size = *size - i - 1;
		ft_strncpy(buffer, buffer + i + 1, *size);
		return (ONE_LINE);
	}
	else
		*size = 0;
	return (LOOP);
}

int	get_next_line(int fd, char **line)
{
	static char			buf[BUFFER_SIZE + 1];
	static int			size;
	char				*out;
	t_state				ret;

	out = NULL;
	ret = LOOP;
	while (ret == LOOP)
		ret = read_line(fd, buf, &out, &size);
	if (ret == ONE_LINE)
		*line = out;
	if (ret == END_FILE)
	{
		*line = copy_buffer(out, "", 0);
		if (*line == NULL)
			return (ERROR);
	}
	return (ret);
}
