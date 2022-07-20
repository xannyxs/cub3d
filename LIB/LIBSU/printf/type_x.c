/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   type_x.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: swofferh <swofferh@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/08 22:26:52 by swofferh      #+#    #+#                 */
/*   Updated: 2022/07/20 13:46:31 by xvoorvaa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	hashtag(t_info *node)
{
	if (node->sign == HASH)
	{
		if (node->conversion == 'x')
			pt_putstr(node, "0x");
		if (node->conversion == 'X')
			pt_putstr(node, "0X");
	}
}

void	width_x(t_info *node, unsigned int nbr, int len)
{
	if (node->width > 0 && node->sign == HASH)
		len += 2;
	if (node->width > 0 && node->flag == NOFLAG)
		pt_putlen(node, ' ', node->width - len);
	if (nbr != 0)
		hashtag(node);
	if (node->width > 0 && node->flag == ZERO)
		pt_putlen(node, '0', node->width - len);
	pt_puthexa(node, nbr, node->conversion);
	if (node->width > 0 && node->flag == MINUS)
		pt_putlen(node, ' ', node->width - len);
}

void	preci_x(t_info *node, unsigned int nbr, int len, char c)
{
	int	width;
	int	precision;
	int	prefix;

	prefix = 0;
	width = node->width;
	precision = node->precision;
	if (node->sign == HASH)
		prefix = 2;
	if (width > precision && node->flag == ZERO)
		pt_putlen(node, ' ', width - ft_maxof(precision, len) - prefix);
	if (node->flag == NOFLAG)
		pt_putlen(node, ' ', width - ft_maxof(precision, len) - prefix);
	hashtag(node);
	if (precision > len)
		pt_putlen(node, '0', precision - len);
	pt_puthexa(node, nbr, c);
	if (node->flag == MINUS)
	{
		pt_putlen(node, ' ', width - ft_maxof(precision, len) - prefix);
		if (width < precision)
			pt_putlen(node, ' ', width - ft_maxof(precision, len));
	}
}

void	zero_nbr(t_info *node, int len)
{
	if (node->period == FALSE && node->flag == NOFLAG)
		pt_putlen(node, ' ', node->width - ft_maxof(node->precision, len));
	if (node->period == TRUE && node->flag != MINUS)
		pt_putlen(node, ' ', node->width - node->precision);
	if (node->precision > 0)
		pt_putlen(node, '0', node->precision);
	if (node->precision == 0 && node->width > 0 && node->flag == ZERO)
		pt_putlen(node, '0', node->width - ft_maxof(node->precision, len));
	if (node->period == FALSE && node->width >= 0)
		pt_putchar(node, '0');
	if (node->period == FALSE && node->flag == MINUS)
		pt_putlen(node, ' ', node->width - len);
	if (node->period == TRUE && node->flag == MINUS)
		pt_putlen(node, ' ', node->width - node->precision);
}

void	ft_x_argument(t_info *node)
{
	unsigned int	nbr;
	int				neg;
	int				len;
	char			c;

	nbr = (unsigned int)va_arg(node->argument, unsigned int);
	len = ft_lenbase(nbr, 16);
	c = node->conversion;
	neg = nbr;
	if (nbr == 0)
		zero_nbr(node, len);
	else if (!node->period)
		width_x(node, nbr, len);
	else
		preci_x(node, nbr, len, c);
}
