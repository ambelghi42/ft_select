/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ambelghi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 18:15:17 by ambelghi          #+#    #+#             */
/*   Updated: 2019/06/11 03:16:02 by ambelghi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*new;

	if ((new = (t_list*)malloc(sizeof(t_list))) != NULL)
	{
		if (content_size == 0 || content == NULL)
			new->content = NULL;
		else if ((new->content = ft_memalloc(content_size)) != NULL)
			new->content = ft_memcpy(new->content, content, content_size);
		new->content_size = (!content_size ? 0 : content_size);
		new->next = NULL;
		return (new);
	}
	return (NULL);
}
