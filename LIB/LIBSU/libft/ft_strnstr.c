/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strnstr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: swofferh <swofferh@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/04 17:14:31 by swofferh      #+#    #+#                 */
/*   Updated: 2022/07/02 18:09:42 by swofferh      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
FT_STRNSTR: 
locate of needle in haystack
not more than len charcacters are searched.
*/
char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t		h;
	size_t		needle_len;

	h = 0;
	needle_len = ft_strlen(needle);
	if (needle[0] == '\0')
		return ((char *)haystack);
	while (needle_len <= len && haystack[h] != '\0')
	{
		if (ft_strncmp(&haystack[h], needle, needle_len) == 0)
			return ((char *)(haystack + h));
		h++;
		len--;
	}
	return (0);
}
