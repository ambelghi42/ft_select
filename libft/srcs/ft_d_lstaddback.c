/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_d_lstaddback.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ambelghi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 01:20:02 by ambelghi          #+#    #+#             */
/*   Updated: 2019/07/17 02:04:35 by ambelghi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_d_lstaddback(t_double_list **alst, t_double_list *new)
{
	t_double_list *p;

	if (alst && new)
	{
		if (*alst)
		{
			p = *alst;
			while (p->next != NULL)
				p = p->next;
			p->next = new;
			new->prev = p;
		}
		else
			*alst = new;
	}
}
