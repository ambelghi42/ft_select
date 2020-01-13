/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_d_lstnew.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ambelghi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 01:16:49 by ambelghi          #+#    #+#             */
/*   Updated: 2019/06/17 02:18:15 by ambelghi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_double_list	*ft_d_lstnew(void const *content, size_t content_size)
{
	t_double_list	*new;

	if ((new = (t_double_list*)malloc(sizeof(t_double_list))) != NULL)
	{
		if (content_size == 0 || content == NULL)
			new->content = NULL;
		else if ((new->content = ft_memalloc(content_size)) != NULL)
			new->content = ft_memcpy(new->content, content, content_size);
		new->content_size = content_size;
		new->prev = NULL;
		new->next = NULL;
		return (new);
	}
	return (NULL);
}
