/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cursor.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ambelghi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 16:11:17 by ambelghi          #+#    #+#             */
/*   Updated: 2020/01/13 16:42:59 by ambelghi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_select.h"

void	cs_setter(int nb_elem, int max_col, t_cs *cs, struct winsize size)
{
	if (cs && cs->screen.x < cs->max_len)
		cs->max_len = cs->screen.x - 1;
	if (cs && nb_elem >= size.ws_row - cs->min_row)
	{
		cs->max_row = cs->min_row - 1
			+ (nb_elem / max_col + (nb_elem % max_col == 0 ? 0 : 1));
		cs->max_row = (cs->max_row > size.ws_row ? size.ws_row - 1
				: cs->max_row);
		cs->lines_col = nb_elem / max_col + (nb_elem % max_col == 0 ? 0 : 1);
	}
	else if (cs)
	{
		cs->max_row = cs->min_row - 1 + cs->nb_elem;
		cs->lines_col = cs->nb_elem;
	}
	if (cs && cs->lines_col == 0)
		cs->lines_col = 1;
}

void	cs_set(t_select_lst *list, int max_len)
{
	int				nb_elem;
	int				max_col;
	struct winsize	size;
	t_cs			*cs;

	if (list && (cs = cs_master(NULL, 0)))
	{
		nb_elem = slct_listcount(list);
		ioctl(0, TIOCGWINSZ, &size);
		max_col = (max_len > 0 && max_len < size.ws_col
				? size.ws_col / (max_len + 1) : 1);
		cs->screen.x = size.ws_col;
		cs->screen.y = size.ws_row;
		cs->max_len = max_len;
		cs->nb_elem = nb_elem - 1;
		cs->max_hscroll = cs->max_len - size.ws_col - 1;
		cs_setter(nb_elem, max_col, cs, size);
		cs->max_scroll = (cs->lines_col > size.ws_row
				? cs->lines_col - (size.ws_row) : 0);
		cs->max_col = (max_len + 1) * (cs->nb_elem / cs->lines_col
				- (cs->nb_elem % cs->lines_col != 0 ? 0 : 1));
		cs->nb_lastcol = (cs->nb_elem % cs->lines_col == 0
				? cs->lines_col : cs->nb_elem % cs->lines_col);
	}
}

void	cs_moveme(t_point *ew, t_cs *tmp)
{
	int	modulo;

	if (ew && tmp)
	{
		(*ew).y = tmp->elem;
		(*ew).x = tmp->scroll;
		tmp->col = tmp->min_col + tmp->elem / tmp->lines_col
					* (tmp->max_len + 1);
		modulo = (tmp->lines_col == 1 ? 0 : tmp->elem % tmp->lines_col);
		tmp->row = tmp->min_row + modulo - tmp->scroll;
		tputs(tgoto(tgetstr("cm", NULL), tmp->col, tmp->row), 1, &my_putchar);
		underline_me(tmp, 1);
		tputs(tgoto(tgetstr("cm", NULL), tmp->col, tmp->row), 1, &my_putchar);
	}
}

void	move_cs(t_cs **cs)
{
	t_cs			*tmp;
	t_select_lst	*lst;
	static t_point	ew = {0, 0};
	int				col;

	if (cs && (tmp = *cs))
	{
		if (ew.x == tmp->scroll && ew.y != tmp->elem
				&& (lst = slct_getlst(tmp->list, ew.y + 1)))
		{
			col = (tmp->max_col == 0 ? 0 : tmp->col);
			tputs(tgoto(tgetstr("cm", NULL), col, tmp->row), 1, &my_putchar);
			tmp->h_scroll = 0;
			start_colors(lst, 0);
			print_name(lst, *cs);
			end_colors(lst, 0);
		}
		cs_moveme(&ew, tmp);
	}
}

t_cs	*cs_master(t_select_lst *list, int init)
{
	static t_cs	cs = {0};

	if (init == 1)
	{
		get_cs_position(&cs.min_col, &cs.min_row);
		cs.elem = 0;
		cs.col = 0;
		cs.min_col = 0;
		cs.row = cs.min_row;
		cs.list = list;
		cs.scroll = 0;
		cs.max_scroll = 0;
		cs.h_scroll = 0;
		cs.ret = NULL;
	}
	return (&cs);
}
