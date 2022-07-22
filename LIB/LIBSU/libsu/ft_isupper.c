/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_isupper.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: sofferha <sofferha@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/08/18 17:20:22 by sofferha      #+#    #+#                 */
/*   Updated: 2022/07/20 13:27:51 by xvoorvaa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* 
FT_ISUPPER:
returns zero if character is uppercase.
*/
int	ft_isupper(int c)
{
	return (c >= 65 && c <= 90);
}
