/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lenbase.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: swofferh <swofferh@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/13 20:55:08 by swofferh      #+#    #+#                 */
/*   Updated: 2022/07/20 13:28:52 by xvoorvaa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
FT_BASELEN:
it's like numlen but handy for different num bases.
*/
size_t	ft_lenbase(long long nbr, int base)
{
	size_t	len;

	len = 1;
	if (nbr < 0)
		len++;
	if (base == 1)
	{
		if (nbr < 0)
			nbr = nbr * -1;
		return ((size_t)nbr + len);
	}
	while (nbr / base != 0)
	{
		len++;
		nbr /= base;
	}
	return (len);
}
