/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lst_map.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: swofferh <swofferh@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/26 17:14:12 by swofferh      #+#    #+#                 */
/*   Updated: 2022/07/20 13:39:25 by xvoorvaa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "liblist.h"

/*
** FT_LSTMAP: Iterates the list and applies the function f to
** 	the content of each element. Creates a new list resulting of
** 	the successive applications of the function f. The del function
** 	is here to delete the content of an element if needed. Returns the
** 	new list or NULL if allocation fails.
*/
t_list	*lst_map(t_list *node, void *(*f)(void *), void (*del)(void *))
{
	t_list		*new;
	t_list		*head;
	void		*content;

	(void) content;
	if (!node)
		return (0);
	head = NULL;
	while (node)
	{
		content = (*f)(node->content);
		new = lst_new((*f)(node->content));
		if (!new)
			lst_clear(&node, del);
		lst_add_back(&head, new);
		node = node->next;
	}
	return (head);
}
