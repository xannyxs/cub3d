/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_maxof.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: swofferh <swofferh@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/19 22:03:30 by swofferh      #+#    #+#                 */
/*   Updated: 2022/07/02 18:15:59 by swofferh      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
FT_MAXOF:
perator used on printf a lot to check which int/len is bigger/higher
*/
int	ft_maxof(int v1, int v2)
{
	return ((v1 < v2) ? (v2) : (v1));
}
