/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lst_move_back.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: swofferh <swofferh@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/09 17:21:27 by swofferh      #+#    #+#                 */
/*   Updated: 2021/02/23 12:07:56 by sofferha      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "liblist.h"

/*
** MOVE_BACK: moves content from the beggining to the end of the list.
*/
t_list		*lst_move_back(t_list **node, void *content)
{
	t_list		*new;
	t_list		*node_copy;

	if (!node)
		return (NULL);
	if (!*node)
	{
		*node = lst_new(content);
		return (*node);
	}
	node_copy = *node;
	if (node_copy->next)
		node_copy = node_copy->next;
	new = lst_new(content);
	new->prev = node_copy;
	node_copy->next = new;
	return (new);
}
