/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putlen.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: sofferha <sofferha@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/02 15:49:00 by sofferha      #+#    #+#                 */
/*   Updated: 2022/07/20 13:35:46 by xvoorvaa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putlen(char c, int len)
{
	if (len < 0)
		return (0);
	while (len)
	{
		ft_putchar(c);
		len--;
	}
	return (0);
}
