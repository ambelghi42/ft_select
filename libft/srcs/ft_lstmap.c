/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ambelghi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/19 22:28:42 by ambelghi          #+#    #+#             */
/*   Updated: 2019/04/23 16:09:31 by ambelghi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*next;
	t_list	*new;
	t_list	*lst2;

	if (lst != NULL && (*f) != NULL)
	{
		new = (*f)(lst);
		if (!new || !(new = ft_lstnew(new->content, new->content_size)))
			return (NULL);
		lst = lst->next;
		while (lst != NULL)
		{
			next = lst->next;
			lst2 = (*f)(lst);
			if (!lst2 || !(lst2 = ft_lstnew(lst2->content, lst2->content_size)))
				return (NULL);
			ft_lstaddback(&new, lst2);
			lst = next;
		}
		return (new);
	}
	return (NULL);
}
