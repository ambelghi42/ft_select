/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ambelghi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 16:27:29 by ambelghi          #+#    #+#             */
/*   Updated: 2020/01/13 16:45:02 by ambelghi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"
#include <sys/stat.h>
#include <sys/types.h>
#include "libft.h"
#include <sys/ioctl.h>

int		scroll_nb(t_cs *cs)
{
	int	scroll;
	int	i;

	scroll = 0;
	if (cs && cs->lines_col > 1)
	{
		i = 0;
		while (i++ < (cs->max_col / (cs->max_len + 1) + 1))
		{
			if (cs->elem > cs->lines_col * (i - 1)
					+ (cs->max_row - cs->min_row + cs->scroll)
					&& cs->elem < (cs->lines_col * i) + cs->scroll + 1)
			{
				scroll = cs->elem - (cs->lines_col * (i - 1)
						+ (cs->max_row - cs->min_row + cs->scroll));
				break ;
			}
		}
	}
	return (scroll);
}

void	print_name(t_select_lst *lst, t_cs *cs)
{
	char	tmp_char;

	if (lst && cs)
	{
		if (ft_strlen(lst->name) <= cs->screen.x)
			ft_putstr_fd(lst->name, cs->tty);
		else
		{
			tmp_char = lst->name[cs->screen.x];
			lst->name[cs->screen.x] = '\0';
			ft_putstr_fd(lst->name, cs->tty);
			lst->name[cs->screen.x] = tmp_char;
		}
	}
}

int		back_space(t_cs *cs)
{
	t_select_lst	*tmp;

	if (cs && (tmp = slct_getlst(cs->list, cs->elem + 1)))
	{
		slct_lstdelone(&tmp);
		cs->nb_elem -= 1;
		cs->elem = (cs->elem > cs->nb_elem - 1 ? cs->nb_elem - 1 : cs->elem);
		if (cs->nb_elem == 0 || !cs->list->next)
			return (-1);
		print_col(cs->list, 1);
		move_cs(&cs);
		if (scroll_nb(cs) > 0 && cs->scroll < cs->max_scroll)
			cs->scroll += scroll_nb(cs);
		else if (scroll_nb(cs) > 0)
			cs->scroll -= (cs->lines_col * (cs->col / (cs->max_len + 1))
					+ cs->scroll + 1) - cs->elem;
		if (cs->scroll > cs->max_scroll)
			cs->scroll = cs->max_scroll;
		if (cs->scroll < 0)
			cs->scroll = 0;
		print_col(cs->list, 1);
		move_cs(&cs);
		return (1);
	}
	return (-1);
}

void	ft_enter(t_cs **cs)
{
	char			*ret;
	char			*tmp_str;
	t_select_lst	*tmp;
	int				i;

	if (cs && *cs && (tmp = (*cs)->list))
	{
		ft_clear();
		ret = NULL;
		i = 0;
		while ((tmp = tmp->next))
		{
			if (tmp->is_select && i++ && (tmp_str = ret) >= 0)
			{
				ret = ft_strjoin(ret, " ");
				ft_strdel(&tmp_str);
				tmp_str = ret;
				ret = ft_strjoin(ret, tmp->name);
				ft_strdel(&tmp_str);
			}
		}
		if (i == 0 && (tmp = slct_getlst((*cs)->list, (*cs)->elem + 1)))
			ret = ft_strdup(tmp->name);
		(*cs)->ret = ret;
	}
}

int		check_keys(char *caps)
{
	int				ret;
	struct winsize	w_term;
	t_cs			*cs;

	ret = 0;
	ioctl(STDIN_FILENO, TIOCGWINSZ, &w_term);
	cs = cs_master(NULL, 0);
	if (ft_strcmp(caps, "\e[D") == 0 && (ret = 1))
		arrow_left(cs);
	if (ft_strcmp(caps, "\e[C") == 0 && (ret = 1))
		arrow_right(cs);
	if (ft_strcmp(caps, "\e[B") == 0 && (ret = 1))
		arrow_down(cs);
	if (ft_strcmp(caps, "\e[A") == 0 && (ret = 1))
		arrow_up(cs);
	if (ft_strcmp(caps, " ") == 0 && (ret = 1))
		space_bar(cs);
	if (caps[0] == 127)
		ret = back_space(cs);
	if (caps[0] == 13 && (ret = -1) < 0)
		ft_enter(&cs);
	if (ft_strlen(caps) == 1 && caps[0] == 27 && (ret = -1) < 0)
		ft_clear();
	return (ret);
}
