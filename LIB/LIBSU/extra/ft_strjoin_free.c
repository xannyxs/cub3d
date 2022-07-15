/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strjoin_free.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: xvoorvaa <xvoorvaa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/14 18:54:22 by xvoorvaa      #+#    #+#                 */
/*   Updated: 2022/04/14 18:55:06 by xvoorvaa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <stdlib.h>

char	*ft_strjoin_free(char *str1, char *str2)
{
	int		i;
	int		j;
	char	*strjoin;

	i = 0;
	j = 0;
	if (!str1 || !str2)
		return (NULL);
	strjoin = malloc(sizeof(char) * (ft_strlen(str1) + ft_strlen(str2) + 1));
	if (!strjoin)
		return (NULL);
	while (str1[i] != '\0')
	{
		strjoin[i] = str1[i];
		i++;
	}
	while (str2[j] != '\0')
	{
		strjoin[i + j] = str2[j];
		j++;
	}
	strjoin[i + j] = '\0';
	free(str1);
	return (strjoin);
}
