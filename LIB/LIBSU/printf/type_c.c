/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   type_c.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: swofferh <swofferh@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/08 22:31:04 by swofferh      #+#    #+#                 */
/*   Updated: 2020/09/11 14:45:14 by sofferha      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_c_argument(t_info *node)
{
	char	c;

	c = va_arg(node->argument, int);
	if (!node->width && node->flag == NOFLAG)
		pt_putchar(node, c);
	if (node->flag == MINUS)
	{
		pt_putchar(node, c);
		pt_putlen(node, ' ', node->width - 1);
	}
	else if (node->width > 0 && node->flag == NOFLAG)
	{
		pt_putlen(node, ' ', node->width - 1);
		pt_putchar(node, c);
	}
	else if (node->flag == ZERO)
	{
		pt_putlen(node, '0', node->width - 1);
		pt_putchar(node, c);
	}
}
