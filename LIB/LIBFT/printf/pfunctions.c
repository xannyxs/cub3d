/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pfunctions.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: swofferh <swofferh@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/08 22:27:17 by swofferh      #+#    #+#                 */
/*   Updated: 2020/09/11 14:45:08 by sofferha      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		pt_putsign(t_info *node, int nbr)
{
	if (nbr >= 0)
	{
		if (node->sign == PLUS)
			pt_putchar(node, '+');
		else if (node->sign == SPACE)
			pt_putchar(node, ' ');
	}
	else
	{
		pt_putchar(node, '-');
		nbr = nbr * -1;
	}
	return (nbr);
}

int		pt_putlen(t_info *node, char c, int len)
{
	if (len < 0)
		return (0);
	while (len)
	{
		pt_putchar(node, c);
		len--;
	}
	return (0);
}

void	pt_putnbr(t_info *node, long n)
{
	if (n == INT_MAX)
		pt_putstr(node, "2147483647");
	else if (n == INT_MIN)
		pt_putstr(node, "2147483648");
	else if (n < 0)
	{
		pt_putchar(node, '-');
		n = -n;
	}
	else if (n <= 9)
	{
		pt_putchar(node, n + 48);
	}
	else if (n > 9)
	{
		pt_putnbr(node, n / 10);
		pt_putchar(node, n % 10 + 48);
	}
}

void	pt_putocta(t_info *node, unsigned long n)
{
	if (n > 7)
	{
		pt_putocta(node, n / 8);
		pt_putocta(node, n % 8);
	}
	else
		pt_putchar(node, n % 8 + '0');
}

void	pt_puthexa(t_info *node, unsigned long n, char c)
{
	if (n == UNS_MAX)
	{
		if (c == 'x')
			pt_putstr(node, "ffffffff");
		if (c == 'X')
			pt_putstr(node, "FFFFFFFF");
	}
	else if (n > 15)
	{
		pt_puthexa(node, n / 16, c);
		pt_puthexa(node, n % 16, c);
	}
	else if (n > 9 && c == 'x')
		pt_putchar(node, n + 87);
	else if (n > 9 && c == 'X')
		pt_putchar(node, n + 55);
	else
		pt_putchar(node, n % 16 + '0');
}
