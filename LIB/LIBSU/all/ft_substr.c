/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_substr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: swofferh <swofferh@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/13 20:40:42 by swofferh      #+#    #+#                 */
/*   Updated: 2022/07/02 18:10:03 by swofferh      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
FT_SUBSTR: 
Allocates with malloc and returns
a substring from the string given in argument.
The substring begins at index ’start’ and is of maximum size ’len’.
*/
char		*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*sub;
	size_t			index;
	unsigned int	s_len;

	index = 0;
	if ((!s))
		return (NULL);
	s_len = ft_strlen(s);
	if (start > s_len)
		return (ft_strdup(""));
	if (start + len > s_len)
		len = s_len - start;
	sub = (char *)ft_malloc(len + 1);
	if (!sub)
		return (NULL);
	while (s && len != 0)
	{
		sub[index] = s[start];
		start++;
		index++;
		len--;
	}
	sub[index] = '\0';
	return (sub);
}
