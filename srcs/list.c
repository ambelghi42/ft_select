/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ambelghi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 17:04:24 by ambelghi          #+#    #+#             */
/*   Updated: 2020/01/13 16:40:14 by ambelghi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"
#include "libft.h"

t_select_lst	*params_tolist(char **env)
{
	int				i;
	t_select_lst	*new;

	new = NULL;
	if ((new = slct_lstnew(NULL, 0, 0)))
	{
		i = 0;
		while (env && env[i])
		{
			i++;
			slct_lstaddb(new, slct_lstnew(ft_strdup(env[i]), i, 0));
		}
	}
	return (new);
}

int				slct_listcount(t_select_lst *elem)
{
	int				nb;
	t_select_lst	*tmp;

	nb = 0;
	if ((tmp = elem))
	{
		while ((tmp = tmp->next))
		{
			nb++;
			tmp->i = nb;
		}
	}
	return (nb);
}

t_select_lst	*slct_lstnew(char *var, int i, int is_select)
{
	t_select_lst	*new;

	new = NULL;
	if ((new = (t_select_lst *)malloc(sizeof(t_select_lst))))
	{
		new->prev = NULL;
		new->next = NULL;
		new->name = var;
		new->i = i;
		new->is_select = is_select;
	}
	return (new);
}

void			slct_lstaddb(t_select_lst *start, t_select_lst *new)
{
	t_select_lst	*tmp;

	tmp = NULL;
	if ((tmp = start) && new)
	{
		while (tmp->next)
			tmp = tmp->next;
		new->prev = tmp;
		tmp->next = new;
	}
}

void			slct_lstdelone(t_select_lst **lst)
{
	if (lst && *lst)
	{
		if ((*lst)->prev)
			(*lst)->prev->next = (*lst)->next;
		if ((*lst)->next)
			(*lst)->next->prev = (*lst)->prev;
		ft_strdel(&(*lst)->name);
		ft_memdel((void **)lst);
	}
}
