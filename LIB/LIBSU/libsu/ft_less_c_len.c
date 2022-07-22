/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_less_c_len.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: xvoorvaa <xvoorvaa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/20 13:29:07 by xvoorvaa      #+#    #+#                 */
/*   Updated: 2022/07/20 13:29:13 by xvoorvaa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
FT_LESS_C_LEN: 
ignores all char 'c' from string...
returns the len of new string without any c
*/
int	ft_less_c_len(char *line, char c)
{
	int		i;
	int		x;
	int		len;

	i = 0;
	x = 0;
	len = 0;
	while (line[i])
	{
		if (line[i] == c)
		{
			x++;
		}
		i++;
	}
	len = (i - x) + 1;
	return (len);
}
