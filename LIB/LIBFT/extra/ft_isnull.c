/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_isnull.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: swofferh <swofferh@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/19 20:26:41 by swofferh      #+#    #+#                 */
/*   Updated: 2022/07/06 17:37:05 by swofferh      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libsu.h"

/*
	The isspace() function tests for the NULL on basic input/output.
	   0 nul	 	1 soh	2 stx	3 etx    4 eot    5 enq    6 ack    7 bel
	   8 bs	 	9 ht	10 nl	11 vt    12 np	  13 cr    14 so    15 si
	   16 dle   17 dc1   18 dc2   19 dc3   20 dc4   21 nak   22 syn   23 etb
	   24 can   25 em    26 sub   27 esc   28 fs    29 gs    30 rs    31 us
	   32 sp    127 del
	This function returns 1 when it's true and 0 when it's false.
*/

int		ft_isnull(int c)
{
	return ((c > 0 && c < 32) || (c == 128 && c == 127));
}
