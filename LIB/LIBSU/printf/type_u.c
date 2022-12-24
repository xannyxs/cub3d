/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   type_u.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: swofferh <swofferh@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/08 22:26:52 by swofferh      #+#    #+#                 */
/*   Updated: 2020/09/11 14:45:27 by sofferha      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	width_u(t_info *node, unsigned int nbr, int len)
{
	if (node->flag == MINUS)
	{
		pt_putnbr(node, pt_putsign(node, nbr));
		pt_putlen(node, ' ', node->width - len);
	}
	else if (node->flag == ZERO)
	{
		nbr = pt_putsign(node, nbr);
		pt_putlen(node, '0', node->width - len);
		pt_putnbr(node, nbr);
	}
	else if (node->flag == NOFLAG)
	{
		pt_putlen(node, ' ', node->width - len);
		pt_putnbr(node, pt_putsign(node, nbr));
	}
}

void	preci_u(t_info *node, unsigned int nbr, int len)
{
	if (node->flag == ZERO || node->flag == NOFLAG)
		pt_putlen(node, ' ', node->width - ft_maxof(node->precision, len));
	if (node->precision > len)
		pt_putlen(node, '0', node->precision - len);
	pt_putnbr(node, nbr);
	if (node->flag == MINUS)
	{
		if (node->width < node->precision)
			pt_putlen(node, ' ', node->precision - node->width - len);
		else
			pt_putlen(node, ' ', node->width - ft_maxof(node->precision, len));
	}
}

void	nbr_zero(t_info *node, int nbr, int len)
{
	if (node->period == TRUE && node->precision == 0)
		pt_putlen(node, ' ', node->width);
	else
	{
		if (node->flag == NOFLAG)
			pt_putlen(node, ' ', node->width - ft_maxof(node->precision, len));
		if (node->flag == ZERO)
		{
			if (node->period == FALSE)
				pt_putlen(node, '0', node->width - 1);
			else
				pt_putlen(node, ' ', node->width - node->precision);
		}
		if (node->precision > 0)
			pt_putlen(node, '0', node->precision - 1);
		pt_putnbr(node, nbr);
		if (node->flag == MINUS)
		{
			if (node->period == FALSE)
				pt_putlen(node, ' ', node->width - 1);
			else
				pt_putlen(node, ' ', node->width - node->precision);
		}
	}
}

void	nbr_neg(t_info *node, unsigned int nbr)
{
	if (node->flag == NOFLAG)
		pt_putlen(node, ' ', node->width - ft_maxof(node->precision, 10));
	if (node->precision > 10)
		pt_putlen(node, '0', node->precision - 10);
	if (node->flag == ZERO)
		pt_putlen(node, '0', node->width - ft_maxof(node->precision, 10));
	if (nbr != UNS_MAX)
		pt_putnbr(node, nbr);
	else
		pt_putnbr(node, UNS_MAX);
	if (node->flag == MINUS)
		pt_putlen(node, ' ', node->width - ft_maxof(node->precision, 10));
}

void	ft_u_argument(t_info *node)
{
	unsigned int	nbr;
	int				neg;
	int				len;

	nbr = (unsigned int)va_arg(node->argument, unsigned int);
	len = ft_lenbase(nbr, 10);
	neg = nbr;
	if (node->conversion == 'u')
	{
		if (nbr == 0)
			nbr_zero(node, 0, len);
		else if (neg < 0 || nbr == UNS_MAX)
			nbr_neg(node, nbr);
		else if (!node->precision)
			width_u(node, nbr, len);
		else if (node->precision > 0)
			preci_u(node, nbr, len);
	}
	else if (node->conversion == 'o')
		pt_putocta(node, nbr);
}
