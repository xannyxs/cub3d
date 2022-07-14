/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_free_array.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: xvoorvaa <xvoorvaa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/14 17:22:47 by xvoorvaa      #+#    #+#                 */
/*   Updated: 2022/04/14 17:26:08 by xvoorvaa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	ft_free_array(char **str)
{
	int		i;
	char	**temp;

	i = 0;
	temp = str;
	while (str[i] != NULL)
	{
		free(str[i]);
		i++;
	}
	free(temp);
}
