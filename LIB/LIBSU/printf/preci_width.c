/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   preci_width.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: swofferh <swofferh@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/08 22:27:06 by swofferh      #+#    #+#                 */
/*   Updated: 2022/07/20 13:42:40 by xvoorvaa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	ft_width(t_info *node, const char *str)
{
	int	i;

	i = 0;
	if ((str[i] == '*') || ft_isdigit(str[i]) || str[i] == '-')
	{
		if (ft_isdigit(str[i]) || str[i] == '-')
		{
			node->width = ft_atoi(str);
			while (ft_isdigit(str[i]) || str[i] == '-')
				i++;
		}
		else if (str[i] == '*')
		{
			node->width = va_arg(node->argument, int);
			i++;
		}
		if (node->width < 0)
		{
			node->flag = MINUS;
			node->width *= -1;
		}
	}
	else
		node->width = 0;
	return (i);
}

int	ft_precision(t_info *node, const char *str)
{
	int	i;

	i = 0;
	if (str[i] == '.')
	{
		node->period = TRUE;
		i++;
		i += ft_asterik(node, str + i);
		return (i);
	}
	return (i);
}

int	ft_asterik(t_info *node, const char *str)
{
	int	i;

	i = 0;
	if ((str[i] == '*') || ft_isdigit(str[i]) || (str[i] == '-'))
	{
		if (ft_isdigit(str[i]) || (str[i] == '-'))
		{
			node->precision = ft_atoi(str);
			while (ft_isdigit(str[i]))
				i++;
		}
		else
		{
			node->precision = va_arg(node->argument, int);
			if (node->precision < 0)
				node->period = 0;
			i++;
		}
		return (i);
	}
	else
	{
		node->precision = 0;
		return (i);
	}
}
