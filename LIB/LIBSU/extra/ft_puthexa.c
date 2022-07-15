/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_puthexa.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: sofferha <sofferha@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/08/18 21:40:49 by sofferha      #+#    #+#                 */
/*   Updated: 2022/07/06 17:48:42 by swofferh      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
FT_PUTHEXA: 
Outputs the number in base 16 (hexagram).
*/
void	ft_puthexa(unsigned long n)
{
	if (n > 15)
	{
		ft_puthexa(n / 16);
		ft_puthexa(n % 16);
	}
	else
		ft_putchar(n % 16 + '0');
}
