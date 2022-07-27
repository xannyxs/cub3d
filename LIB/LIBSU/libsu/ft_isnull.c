/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_isnull.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: swofferh <swofferh@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/19 20:26:41 by swofferh      #+#    #+#                 */
/*   Updated: 2022/07/25 12:46:19 by sofferha      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libsu.h"

/*
	FT_ISNULL
	(c == 128 && c == 127 || c = '\0')
	This function returns 1 when it's true and 0 when it's false.
*/
int	ft_isnull(char c)
{
	return ((int)c == 128 || (int)c == 127 || c == '\0');
}
