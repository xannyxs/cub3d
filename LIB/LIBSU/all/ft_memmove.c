/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memmove.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: swofferh <swofferh@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/04 17:13:30 by swofferh      #+#    #+#                 */
/*   Updated: 2022/07/02 18:06:24 by swofferh      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
FT_MEMMOVE: 
Non-destructively copies len bytes
From string src to string dst. The two strings may overlap
returns the original value of dst.
*/
void	*ft_memmove(void *dst, const void *src, size_t len)
{
	if (!dst && !src)
		return (NULL);
	if (dst < src)
		ft_memcpy(dst, src, len);
	else if (dst > src)
		while (len)
		{
			len--;
			((char *)dst)[len] = ((char *)src)[len];
		}
	return (dst);
}
