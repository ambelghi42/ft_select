/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ambelghi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 16:39:42 by ambelghi          #+#    #+#             */
/*   Updated: 2020/01/13 16:41:34 by ambelghi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"
#include "libft.h"

t_select_lst	*slct_dup(t_select_lst *list)
{
	t_select_lst	*new;
	t_select_lst	*tmp;

	new = NULL;
	tmp = list;
	if ((new = slct_lstnew(NULL, 0, 0)))
	{
		while ((tmp = tmp->next))
		{
			slct_lstaddb(new, slct_lstnew(ft_strdup(tmp->name), tmp->i,
						tmp->is_select));
		}
	}
	return (new);
}

t_select_lst	*slct_getlst(t_select_lst *list, int n)
{
	t_select_lst	*tmp;
	int				i;

	if ((tmp = list))
	{
		i = 1;
		while (tmp && tmp->prev)
			tmp = tmp->prev;
		while (tmp->next && (tmp = tmp->next) && i++ < n)
			;
	}
	return (tmp);
}

void			slct_lstfree(t_select_lst **lst)
{
	t_select_lst	*tmp;
	t_select_lst	*next;

	if (lst && (tmp = *lst))
	{
		while (tmp)
		{
			next = tmp->next;
			if (tmp->name)
				ft_strdel(&tmp->name);
			ft_memdel((void **)&tmp);
			tmp = next;
		}
	}
}
