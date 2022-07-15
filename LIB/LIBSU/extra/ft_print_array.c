/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_print_array.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: xvoorvaa <xvoorvaa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/03 16:12:23 by xvoorvaa      #+#    #+#                 */
/*   Updated: 2022/06/07 17:41:45 by xvoorvaa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_array(char *array[])
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (array[y] != NULL)
	{
		while (array[y][x] != '\0')
		{
			write(STDOUT_FILENO, &array[y][x], 1);
			x++;
		}
		write(STDOUT_FILENO, "\n", 1);
		x = 0;
		y++;
	}
}
