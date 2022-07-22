/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putocta.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: sofferha <sofferha@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/08/18 21:43:52 by sofferha      #+#    #+#                 */
/*   Updated: 2022/07/06 17:58:48 by swofferh      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
FT_PUTOCTAL: 
Outputs the number in base 8 (octals).
*/
void	ft_putoctal(unsigned long n)
{
	if (n > 7)
	{
		ft_putoctal(n / 8);
		ft_putoctal(n % 8);
	}
	else
		ft_putchar(n % 8 + '0');
}
