/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strrchr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: swofferh <swofferh@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/04 17:13:21 by swofferh      #+#    #+#                 */
/*   Updated: 2022/07/02 18:09:48 by swofferh      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
FT_STRRCHR: 
locate last occurence of character c in string and then
returns a pointer to the located character, NULL if it does not appear.
*/
char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*str;
	char	cha;

	i = ft_strlen(s);
	cha = (char)c;
	str = (char *)s;
	while (str[i] != cha)
	{
		if (i == 0)
			return (NULL);
		i--;
	}
	return (&str[i]);
}
