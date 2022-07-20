/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lst_clear.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: swofferh <swofferh@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/26 17:23:57 by swofferh      #+#    #+#                 */
/*   Updated: 2022/07/20 13:39:11 by xvoorvaa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "liblist.h"

/*
** FT_LSTCLEAR: Deletes and frees the given element and every
** 	successor of that element, using the function del and free.
** 	Finally, the pointer to the list must be set to NULL.
*/
void	lst_clear(t_list **node, void (*del)(void*))
{
	t_list		*link;
	t_list		*next_link;

	if (!(node))
		return ;
	link = *node;
	while (link)
	{
		next_link = link->next;
		del(link->content);
		free(link);
		link = next_link;
	}
	*node = NULL;
}
