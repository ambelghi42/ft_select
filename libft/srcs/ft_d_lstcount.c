/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_d_lstcount.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ambelghi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 17:34:01 by ambelghi          #+#    #+#             */
/*   Updated: 2019/09/25 18:58:20 by ambelghi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_d_lstcount(t_double_list *elem)
{
	int				nb;
	t_double_list	*tmp;

	nb = 0;
	if ((tmp = elem))
	{
		while ((tmp = tmp->next))
			nb++;
	}
	return (nb);
}
