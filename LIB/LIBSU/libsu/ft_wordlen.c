/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_wordlen.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: swofferh <swofferh@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/13 20:53:06 by swofferh      #+#    #+#                 */
/*   Updated: 2022/07/20 13:36:22 by xvoorvaa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
MY_WORDLEN:
counts the amout of chars/letters in a word.
*/
int	ft_wordlen(char const *str, int i, char space)
{
	int	len;

	len = 0;
	while (str[i] && str[i] != space)
	{
		len++;
		i++;
	}
	return (len);
}
