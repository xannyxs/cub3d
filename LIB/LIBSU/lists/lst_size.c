/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lst_size.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: swofferh <swofferh@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/26 17:20:11 by swofferh      #+#    #+#                 */
/*   Updated: 2022/07/20 13:39:34 by xvoorvaa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "liblist.h"

/*
** FT_LSTSIZE: Counts the number of elements size_t a list
** 	and returns the length of the list.
*/
size_t	lst_size(t_list *node)
{
	size_t		index;

	index = 0;
	while (node)
	{
		node = node->next;
		index++;
	}
	return (index);
}
