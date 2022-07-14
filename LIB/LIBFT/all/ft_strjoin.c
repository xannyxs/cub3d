/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strjoin.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: swofferh <swofferh@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/13 20:47:54 by swofferh      #+#    #+#                 */
/*   Updated: 2022/07/02 18:14:31 by swofferh      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
FT_STRJOIN: 
Joins one string to the end of another.
returns new string, the result after appending.
*/
char			*ft_strjoin(char const *s1, char const *s2)
{
	char	*new;
	int		len1;
	int		len2;
	size_t	a;
	size_t	b;

	a = 0;
	b = 0;
	if (!s1 || !s2)
		return (NULL);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	new = (char *)malloc((len1 + len2) + 1);
	if (new == NULL)
		return (NULL);
	while (s1[a])
	{
		new[a] = s1[a];
		a++;
	}
	while (s2[b])
	{
		new[a] = s2[b];
		a++;
		b++;
	}
	new[a] = '\0';
	return (new);
}
