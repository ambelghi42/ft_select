/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_d_lstnew2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ambelghi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 23:53:31 by ambelghi          #+#    #+#             */
/*   Updated: 2019/09/11 00:00:13 by ambelghi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_double_list	*ft_d_lstnew2(void *content)
{
	t_double_list	*new;

	if ((new = (t_double_list*)malloc(sizeof(t_double_list))) != NULL)
	{
		new->content = content;
		new->content_size = 0;
		new->prev = NULL;
		new->next = NULL;
		return (new);
	}
	return (NULL);
}
