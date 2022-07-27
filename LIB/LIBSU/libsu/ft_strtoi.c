/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strtoi.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: xvoorvaa <xvoorvaa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/25 16:39:04 by xvoorvaa      #+#    #+#                 */
/*   Updated: 2022/07/25 17:07:33 by xvoorvaa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>

static int	ignore_whitespace(const char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] < 33)
		i++;
	if (str[i] == '\e' || ((str[i] < '0' || str[i] > '9')
			&& (str[i] != '+' && str[i] != '-')))
	{
		errno = EINVAL;
		return (0);
	}
	return (i);
}

int	ft_strtoi(const char *str)
{
	int	i;
	int	negative;
	int	answer;

	answer = 0;
	negative = 1;
	i = ignore_whitespace(str);
	if (errno == EINVAL)
		return (0);
	while (str[i] != '\0')
	{
		if (str[i] == '-')
			negative = -1;
		else if (str[i] >= '0' && str[i] <= '9')
			answer = answer * 10 + (str[i] - '0');
		if (str[i + 1] < '0' || str[i + 1] > '9')
			return (negative * answer);
		i++;
	}
	errno = EINVAL;
	return (0);
}
