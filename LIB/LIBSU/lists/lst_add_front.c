/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lst_add_front.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: swofferh <swofferh@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/09 17:20:34 by swofferh      #+#    #+#                 */
/*   Updated: 2021/02/23 12:08:07 by sofferha      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "liblist.h"

/*
** FT_LSTADD_FRONT: Adds the element new at the beginning of the list.
*/
void		lst_add_front(t_list **old, t_list *new)
{
	if (!(old) || (!(new)))
		return ;
	new->next = *old;
	*old = new;
}
