/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_atol.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: xvoorvaa <xvoorvaa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/02 20:05:24 by xvoorvaa      #+#    #+#                 */
/*   Updated: 2021/12/02 20:05:30 by xvoorvaa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

long	ft_atol(const char *str)
{
	int		i;
	int		negative;
	long	answer;

	i = 0;
	answer = 0;
	negative = 1;
	while (str[i] && str[i] < 33)
		i++;
	if (str[i] == '\e' || ((str[i] < '0' || str[i] > '9')
			&& (str[i] != '+' && str[i] != '-')))
		return (0);
	while (str[i] != '\0')
	{
		if (str[i] == '-')
			negative = -1;
		else if (str[i] >= '0' && str[i] <= '9')
			answer = answer * 10 + (str[i] - '0');
		if (str[i + 1] < '0' || str[i + 1] > '9')
			return (negative * answer);
		i++;
	}
	return (0);
}
