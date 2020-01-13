/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ambelghi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/19 21:56:01 by ambelghi          #+#    #+#             */
/*   Updated: 2019/04/23 16:04:05 by ambelghi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(t_list *elem))
{
	t_list	*next;

	if ((*f) != NULL && lst != NULL)
	{
		while (lst != NULL)
		{
			next = lst->next;
			(*f)(lst);
			lst = next;
		}
	}
}
