/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strndup.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: swofferh <swofferh@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/13 20:40:42 by swofferh      #+#    #+#                 */
/*   Updated: 2022/07/22 14:03:19 by swofferh      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

/*
FT_STRNDUP: 
Skips n amount of chars. Allocates with malloc and returns
a substring from the string given in argument beginning at index ’start’.
*/
char	*ft_strndup(char *s, int start)
{
	int		index;
	int		s_len;
	char	*sub;

	index = 0;
	if ((!s))
		return (NULL);
	s_len = ft_strlen(s);
	if (start > s_len)
		return (NULL);
	sub = (char *)ft_malloc(s_len - start + 1);
	if (!sub)
		return (NULL);
	while (s[start])
	{
		sub[index] = s[start];
		start++;
		index++;
	}
	sub[index] = '\0';
	return (sub);
}
