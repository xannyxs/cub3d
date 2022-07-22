/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strncmp.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: swofferh <swofferh@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/04 21:14:35 by swofferh      #+#    #+#                 */
/*   Updated: 2022/07/19 23:42:24 by xvoorvaa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
FT_STRNCMP: 
compares two strings lexographically...
returns 1 if s1 is bigger than s2
returns 0 if equal
returns -1 if smaller
*/
int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*first;
	unsigned char	*second;

	first = (unsigned char *)s1;
	second = (unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if (s1[i] != s2[i])
			return (first[i] - second[i]);
		if (s1[i] == '\0')
			return (0);
		i++;
	}
	return (0);
}
