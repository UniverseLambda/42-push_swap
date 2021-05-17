/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clsaad <clsaad@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 11:38:56 by clsaad            #+#    #+#             */
/*   Updated: 2020/12/08 11:38:56 by clsaad           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LIST_H
# define FT_LIST_H

# include <stddef.h>

struct s_list
{
	void			*content;
	struct s_list	*next;
};

typedef struct s_list	t_list;

t_list	*ft_lstnew(void *content);
void	ft_lstadd_front(t_list **alst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	*ft_lstget(t_list *lst, size_t index);

/*
** Note: if the (t_list *) pointed by `alst` is NULL, then it is set to `new`
*/

void	ft_lstadd_back(t_list **alst, t_list *new);
int		ft_lstpush_back(t_list **list, void *data);
void	ft_lstdelone(t_list *lst, void (*del)(void*));

/*
** Note: this method does not SEGFAULT when the (t_list *) pointed by `lst` is
** NULL and returns without doing anything instead.
*/

void	ft_lstclear(t_list **lst, void (*del)(void*));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

#endif // FT_LIST_H
