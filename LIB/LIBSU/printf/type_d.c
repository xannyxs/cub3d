/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   type_d.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: swofferh <swofferh@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/08 22:26:52 by swofferh      #+#    #+#                 */
/*   Updated: 2022/07/20 13:50:27 by xvoorvaa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	width_d(t_info *node, int nbr, int len)
{
	if (nbr > 0 && node->sign != 0)
		len++;
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

void	check_extra_flags(t_info *node, int nbr, int len, int neg)
{
	if (node->flag == ZERO || node->flag == NOFLAG)
	{
		nbr = pt_putsign(node, nbr);
		pt_putlen(node, '0', node->precision - len + neg);
		pt_putnbr(node, nbr);
	}
}

void	preci_d(t_info *node, int nbr, int len)
{
	int	preci;
	int	sign;
	int	neg;

	neg = 0;
	sign = 0;
	preci = node->precision;
	if (nbr < 0)
		neg++;
	if (node->sign != 0)
		sign++;
	if (node->flag == MINUS)
	{
		nbr = pt_putsign(node, nbr);
		pt_putlen(node, '0', node->precision - len + neg);
		pt_putnbr(node, nbr);
	}
	if (preci < node->width)
	{
		pt_putlen(node, ' ', node->width - ft_maxof(preci, len) - sign - neg);
		if (preci <= len)
			pt_putlen(node, ' ', neg);
	}
	check_extra_flags(node, nbr, len, neg);
}

void	process_zero(t_info *node, int nbr)
{
	if (node->sign != 0)
		node->width--;
	if (node->period == TRUE)
	{
		if (node->flag == ZERO || node->flag == NOFLAG)
			pt_putlen(node, ' ', node->width - node->precision);
		if (node->sign != 0)
			pt_putsign(node, nbr);
		pt_putlen(node, '0', node->precision);
		if (node->flag == MINUS)
			pt_putlen(node, ' ', node->width - node->precision);
	}
	else
	{
		if (node->flag == NOFLAG)
			pt_putlen(node, ' ', node->width - 1);
		if (node->sign != 0)
			pt_putsign(node, nbr);
		if (node->flag == ZERO)
			pt_putlen(node, '0', node->width - 1);
		pt_putnbr(node, nbr);
		if (node->flag == MINUS)
			pt_putlen(node, ' ', node->width - 1);
	}
}

void	ft_d_argument(t_info *node)
{
	int	nbr;
	int	len;
	int	sign;

	sign = 0;
	nbr = va_arg(node->argument, int);
	len = ft_lenbase(nbr, 10);
	if (nbr == 0)
		process_zero(node, 0);
	else if (!node->period)
	{
		if (!node->width)
			pt_putnbr(node, pt_putsign(node, nbr));
		else
			width_d(node, nbr, len);
	}
	else
		preci_d(node, nbr, len);
}
