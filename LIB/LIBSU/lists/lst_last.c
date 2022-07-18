/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lst_last.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: swofferh <swofferh@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/26 17:18:44 by swofferh      #+#    #+#                 */
/*   Updated: 2021/02/23 12:08:00 by sofferha      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "liblist.h"

/*
** FT_LSTLAST: Returns the last element of the list.
*/
t_list		*lst_last(t_list *lst)
{
	if (lst)
		while (lst->next)
			lst = lst->next;
	return (lst);
}
