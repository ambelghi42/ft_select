/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_d_lstdelone.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ambelghi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 01:26:36 by ambelghi          #+#    #+#             */
/*   Updated: 2019/06/20 20:11:02 by ambelghi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_d_lstdelone(t_double_list **elem)
{
	t_double_list	*prev;
	t_double_list	*next;
	t_double_list	*tmp;

	if (elem && *elem)
	{
		tmp = *elem;
		if ((prev = tmp->prev))
			prev->next = tmp->next;
		if ((next = tmp->next))
			next->prev = prev;
		ft_memdel(&(tmp)->content);
		free(*elem);
		*elem = NULL;
	}
}
