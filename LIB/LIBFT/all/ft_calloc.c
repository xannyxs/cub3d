/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_calloc.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: swofferh <swofferh@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/04 17:14:27 by swofferh      #+#    #+#                 */
/*   Updated: 2022/07/02 18:16:18 by swofferh      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* 
FT_CALLOC: 
contiguously allocates enough space for count objects that
are size bytes of memory each and returns a pointer to the allocated memory. The allocated memory is filled with bytes of value zero.
*/
void	*ft_calloc(size_t count, size_t size)
{
	void	*objects;

	objects = (void *)malloc(count * size);
	if (objects == NULL)
		return (NULL);
	ft_bzero(objects, count * size);
	return (objects);
}
