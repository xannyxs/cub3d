/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_isspace.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: sofferha <sofferha@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/08/18 17:20:22 by sofferha      #+#    #+#                 */
/*   Updated: 2022/07/25 11:46:33 by sofferha      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* 
	FT_ISSPACE: 
	Also for '\n' '\t' '\v' '\f' '\r'
	The isspace() function tests for empty spaces on basic input/output.
	   0 nul	 	1 soh		2 stx	3 etx    	4 eot    5 enq    6 ack    7 bel
	   8 bs	 	9 ht		10 nl	11 vt    	12 np	  	13 cr    14 so    15 si
	   16 dle   17 dc1   18 dc2   19 dc3   20 dc4   21 nak   22 syn   23 etb
	   24 can   25 em    26 sub   27 esc   28 fs    29 gs    30 rs    31 us
	   32 sp    127 del
	Returns 1 when it's true and 0 when it's false.
*/
int	ft_isspace(char c)
{
	return ((int)c > 0 && (int)c <= 32);
}
