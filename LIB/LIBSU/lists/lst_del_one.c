/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lst_del_one.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: swofferh <swofferh@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/26 17:22:59 by swofferh      #+#    #+#                 */
/*   Updated: 2022/07/20 13:39:18 by xvoorvaa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "liblist.h"

/*
** FT_LSTDELONE: Takes as a parameter an element and frees the memory
** 	of the element’s content using the function del given as a parameter.
** 	The memory of 'next' must not be freed under any circumstance.
*/
void	lst_del_one(t_list *node, void (*del)(void*))
{
	if (!(node))
		return ;
	if (node)
		del(node->content);
	free(node);
	node = NULL;
}
