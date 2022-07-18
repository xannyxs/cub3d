/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   liblist.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: swofferh <swofferh@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/28 17:10:52 by swofferh      #+#    #+#                 */
/*   Updated: 2021/02/23 12:24:20 by sofferha      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBLIST_H
# define LIBLIST_H

# include <unistd.h>
# include <stdlib.h>

typedef struct s_list	t_list;

struct				s_list
{
	void			*content;
	t_list			*next;
	t_list			*prev;
};

void				lst_reverse(t_list **node);
void				lst_add_front(t_list **old, t_list *new);
void				lst_add_back(t_list **old, t_list *new);
void				lst_del_one(t_list *node, void (*del)(void*));
void				lst_clear(t_list **node, void (*del)(void*));
void				lst_new_front(t_list **node, void *content);
void				lst_itter(t_list *node, void (*f)(void *));
void				*lst_move_front(t_list **node, void *content);
t_list				*lst_move_back(t_list **node, void *content);
size_t				lst_size(t_list *node);
t_list				*lst_last(t_list *node);
t_list				*lst_new(void *content);
t_list				*lst_new_back(t_list **node, void *content);
t_list				*lst_map(t_list *node, void *(*f)(void *), void (*del)\
(void *));

void				*ft_malloc(size_t size);

#endif
