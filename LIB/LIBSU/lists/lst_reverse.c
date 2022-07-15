/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lst_reverse.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: swofferh <swofferh@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/26 17:24:47 by swofferh      #+#    #+#                 */
/*   Updated: 2021/02/23 18:50:44 by sofferha      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "liblist.h"

/*
** MY_REVERSE: Counts the number of elements size_t a list
** 	and returns the length of the list.
*/
void	lst_reverse(t_list **node)
{
	t_list	*node_cpy;
	t_list	*tmp;

	if (!node)
		return ;
	if (!*node)
		return ;
	node_cpy = *node;
	tmp = NULL;
	while (node_cpy)
	{
		tmp = node_cpy->prev;
		node_cpy->prev = node_cpy->next;
		node_cpy->next = tmp;
		node_cpy = node_cpy->prev;
	}
	*node = tmp->prev;
}
