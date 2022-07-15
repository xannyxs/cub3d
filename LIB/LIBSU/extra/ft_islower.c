/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_islower.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: sofferha <sofferha@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/08/18 17:20:22 by sofferha      #+#    #+#                 */
/*   Updated: 2022/07/02 18:07:33 by swofferh      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* 
FT_ISLOWER: 
returns zero if character is lowcase.
*/
int		ft_islower(int c)
{
	return (c >= 97 && c <= 122);
}
