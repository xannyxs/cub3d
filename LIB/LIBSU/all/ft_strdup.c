/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strdup.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: swofferh <swofferh@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/04 17:21:01 by swofferh      #+#    #+#                 */
/*   Updated: 2022/07/02 18:14:35 by swofferh      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <errno.h>

/*
FT_STRDUP: 
allocates sufficient memory for a copy of
the string s1, does the copy, and returns a pointer to it.
*/
char	*ft_strdup(const char *s1)
{
	size_t		i;
	size_t		len;
	char		*dup;

	len = 0;
	while (s1[len])
		len++;
	dup = (char *)ft_malloc(sizeof(char) * (ft_strlen(s1) + 1));
	if (!dup)
		ENOMEM;
	if (dup == NULL)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		dup[i] = s1[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}
