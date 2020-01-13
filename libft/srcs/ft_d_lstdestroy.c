/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_d_lstdestroy.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ambelghi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 20:54:27 by ambelghi          #+#    #+#             */
/*   Updated: 2019/07/07 22:48:11 by ambelghi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_d_lstdestroy(t_double_list **begin)
{
	t_double_list	*tmp;
	t_double_list	*next;

	if (begin && *begin)
	{
		tmp = *begin;
		if (tmp->prev)
		{
			while (tmp && tmp->prev)
				tmp = tmp->prev;
		}
		while (tmp)
		{
			next = tmp->next;
			ft_d_lstdelone(&tmp);
			tmp = next;
		}
		*begin = NULL;
	}
}
