/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_nospace.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: xvoorvaa <xvoorvaa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/20 13:29:39 by xvoorvaa      #+#    #+#                 */
/*   Updated: 2022/08/03 15:42:57 by xvoorvaa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
	FT_NOSPACE: 
	removes all spaces...
	returns the new string without spaces
*/
char	*ft_nospace(char *line)
{
	char	*str;
	int		i;
	int		x;
	int		len;

	i = 0;
	x = 0;
	len = 0;
	if (!line)
		return (NULL);
	len = ft_less_c_len(line, ' ');
	str = (char *)ft_malloc(sizeof(char) * len);
	while (line[i])
	{
		if (line[i] != ' ')
		{
			str[x] = line[i];
			x++;
		}
		i++;
	}
	str[x] = '\0';
	free(line);
	return (str);
}
