/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memcpy.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: swofferh <swofferh@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/01 16:59:00 by swofferh      #+#    #+#                 */
/*   Updated: 2022/07/02 18:06:22 by swofferh      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
FT_MEMCPY: 
copy memory area
copies n bytes from memory area src to memory area dest.
*/
void		*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t		i;
	char		*s1;
	char		*s2;

	if (!dst && !src)
		return (dst);
	i = 0;
	s1 = (char *)dst;
	s2 = (char *)src;
	while (i < n)
	{
		s1[i] = s2[i];
		i++;
	}
	return (dst);
}
