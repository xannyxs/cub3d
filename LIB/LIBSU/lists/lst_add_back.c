/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lst_add_back.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: swofferh <swofferh@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/09 17:21:27 by swofferh      #+#    #+#                 */
/*   Updated: 2022/07/20 13:38:52 by xvoorvaa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "liblist.h"

/*
** FT_LSTADD_BACK: Adds the element new at the end of the list.
*/
void	lst_add_back(t_list **old, t_list *new)
{
	t_list	*head;

	if (!(old))
		return ;
	head = *old;
	if (head)
	{
		while (head->next)
			head = head->next;
		head->next = new;
	}
	else
		lst_add_front(old, new);
}
