/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putbase.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: swofferh <swofferh@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/28 18:21:22 by swofferh      #+#    #+#                 */
/*   Updated: 2022/07/06 17:35:17 by swofferh      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libsu.h"

void	ft_putbase(char *str, int index, int base)
{
	char c;

	c = ft_itoa(index);
	while (str[index])
	{
		if (ft_isdigit(index) == 1)
		{
			if (base == 10)
				ft_putnbr(index);
			if (base == 16)
				ft_puthexa((unsigned long)(index));
			if (base == 8)
				ft_putocta((unsigned long)(index));
			else
				ft_putbase((long long)index, base);
		}
		if (base = 0)
			ft_putendl(str);
		else
			ft_putchar(c);
	}
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *s)
{
	write(1, s, ft_strlen(s));
}

void	ft_putendl(char *s)
{
	ft_putstr(s);
	ft_putchar('\n');
}

void	ft_putnbr(int n)
{
	if (n == -2147483648)
	{
		ft_putstr("-2147483648");
		return ;
	}
	else if (n < 0)
	{
		ft_putchar('-');
		ft_putnbr(-n);
	}
	else if (n > 9)
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
	else
		ft_putchar(n % 10 + '0');
	return ;
}

void	ft_putocta(unsigned long n)
{
	if (n > 7)
	{
		ft_putocta(n / 8);
		ft_putocta(n % 8);
	}
	else
		ft_putchar(n % 8 + '0');
}

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

void	ft_putbase(long long n, int base)
{
	if (n > 15)
	{
		ft_putbase(n / base, base);
		ft_putbase(n % base, base);
	}
	else
		ft_putchar(n % base + '0');
}