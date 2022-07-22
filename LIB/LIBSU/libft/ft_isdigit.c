/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_isdigit.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: swofferh <swofferh@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/31 18:18:49 by swofferh      #+#    #+#                 */
/*   Updated: 2022/07/19 23:35:06 by xvoorvaa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* 
		FT_ISDIGIT: 
		tests for a decimal digit character (0 - 9)
		returns zero if character tests false, non-zero is true.
*/
int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}
