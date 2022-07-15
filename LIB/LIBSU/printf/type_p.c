/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   type_p.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: swofferh <swofferh@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/08 22:26:52 by swofferh      #+#    #+#                 */
/*   Updated: 2020/09/11 14:45:21 by sofferha      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	preci_p(t_info *node, unsigned long nbr, int len, int ox)
{
	int width;
	int preci;

	width = node->width;
	preci = node->precision;
	if (node->flag == NOFLAG)
		pt_putlen(node, ' ', width - ft_maxof(len, preci) - ox);
	pt_putstr(node, "0x");
	if (preci > len)
		pt_putlen(node, '0', preci - len);
	if (node->flag == ZERO)
		pt_putlen(node, '0', width - ft_maxof(len, preci) - ox);
	pt_puthexa(node, nbr, 'x');
	if (node->flag == MINUS)
		pt_putlen(node, ' ', width - ft_maxof(len, preci) - ox);
}

void	ft_p_argument(t_info *node)
{
	unsigned long	nbr;
	int				len;
	int				ox;

	ox = 2;
	nbr = (unsigned long)va_arg(node->argument, void *);
	len = ft_lenbase(nbr, 16);
	if (nbr == 0 && node->period == TRUE && node->precision == 0)
	{
		if (node->flag == NOFLAG || node->flag == ZERO)
			pt_putlen(node, ' ', node->width - ox);
		pt_putstr(node, "0x");
		if (node->flag == MINUS)
			pt_putlen(node, ' ', node->width - ox);
	}
	else
		preci_p(node, nbr, len, ox);
}

void	ft_no_argument(t_info *node)
{
	if (!node->width && node->flag == NOFLAG)
		pt_putchar(node, '%');
	if (node->flag == MINUS)
	{
		pt_putchar(node, '%');
		pt_putlen(node, ' ', node->width - 1);
	}
	else if (node->width > 0 && node->flag == NOFLAG)
	{
		pt_putlen(node, ' ', node->width - 1);
		pt_putchar(node, '%');
	}
	else if (node->flag == ZERO)
	{
		pt_putlen(node, '0', node->width - 1);
		pt_putchar(node, '%');
	}
}
