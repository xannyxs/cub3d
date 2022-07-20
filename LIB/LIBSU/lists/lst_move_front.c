/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lst_move_front.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: swofferh <swofferh@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/09 17:21:27 by swofferh      #+#    #+#                 */
/*   Updated: 2022/07/20 13:40:08 by xvoorvaa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "liblist.h"

/*
** MOVE_FRONT: Adds content from the end of the list the the very beggining.
*/
void	*lst_move_front(t_list **node, void *content)
{
	t_list	*new;

	if (!node)
		return (NULL);
	if (!*node)
	{
		*node = lst_new(content);
		return (*node);
	}
	new = lst_new(content);
	new->next = *node;
	(*node)->next = new;
	*node = new;
	return (new);
}
