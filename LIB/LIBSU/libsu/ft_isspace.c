/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_isspace.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: sofferha <sofferha@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/08/18 17:20:22 by sofferha      #+#    #+#                 */
/*   Updated: 2022/07/22 15:35:49 by swofferh      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* 
FT_ISSPACE: 
returns zero if character empty space. 
*/
int	ft_isspace(char c)
{
	return (c == '\n' || c == '\t' || c == ' ' || \
		c == '\v' || c == '\f' || c == '\r');
}
