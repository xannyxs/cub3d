/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strclen.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: swofferh <swofferh@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/28 17:31:45 by swofferh      #+#    #+#                 */
/*   Updated: 2022/07/19 23:38:37 by xvoorvaa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
FT_STRLEN: 
Computes the length of the string s
returns the number of characters that precede
the terminating NUL character.
*/
int	ft_strclen(char *str, char c)
{
	int	index;

	index = 0;
	while (str[index] && str[index] != c)
		index++;
	return (index);
}
