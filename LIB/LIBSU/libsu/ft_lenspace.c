/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lenspace.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: swofferh <swofferh@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/02 15:41:00 by swofferh      #+#    #+#                 */
/*   Updated: 2022/08/02 15:45:19 by swofferh      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int ft_lenspace(char *str)
{
	int	len;

	len = 0;
	while (ft_isspace(str[len]) == 1)
		len++;
	return (len);
}