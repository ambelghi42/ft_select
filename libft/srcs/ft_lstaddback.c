/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstaddback.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ambelghi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/20 00:42:50 by ambelghi          #+#    #+#             */
/*   Updated: 2019/04/20 20:34:05 by ambelghi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstaddback(t_list **alst, t_list *new)
{
	t_list *p;

	if (alst != NULL && new != NULL && *alst != NULL)
	{
		p = (*alst);
		while (p->next != NULL)
			p = p->next;
		p->next = new;
	}
}
