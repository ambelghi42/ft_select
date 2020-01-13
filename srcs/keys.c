/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_arrows2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ambelghi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/23 14:45:32 by ambelghi          #+#    #+#             */
/*   Updated: 2020/01/13 16:29:11 by ambelghi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"
#include <sys/stat.h>
#include <sys/types.h>
#include "libft.h"
#include <sys/ioctl.h>

void	arrow_up(t_cs *cs)
{
	if (cs)
	{
		underline_me(cs, 0);
		if (cs->elem > 0)
			cs->elem -= 1;
		else
			cs->elem = cs->nb_elem - 1;
		if (cs->row == cs->min_row && cs->scroll > 0
				&& (cs->scroll -= 1) >= 0)
			print_col(cs->list, 1);
		else if (cs->row == cs->min_row && cs->scroll < cs->max_scroll
				&& (cs->col == cs->max_col || scroll_nb(cs) > 0)
				&& (cs->scroll += scroll_nb(cs)))
			print_col(cs->list, 1);
		move_cs(&cs);
	}
}

void	arrow_down(t_cs *cs)
{
	if (cs)
	{
		underline_me(cs, 0);
		if (cs->elem + 1 <= cs->nb_elem - 1)
			cs->elem += 1;
		else
			cs->elem = 0;
		if ((cs->elem == 0 || cs->elem % cs->lines_col == 0)
				&& cs->scroll > 0 && (cs->scroll = 0) == 0)
			print_col(cs->list, 1);
		else if (cs->row == cs->max_row && cs->scroll < cs->max_scroll
				&& (cs->col == cs->max_col || scroll_nb(cs) > 0)
				&& (cs->scroll += scroll_nb(cs)))
			print_col(cs->list, 1);
		move_cs(&cs);
	}
}

void	arrow_right(t_cs *cs)
{
	if (cs)
	{
		underline_me(cs, 0);
		if (cs->col < cs->max_col && cs->elem + cs->lines_col < cs->nb_elem)
			cs->elem += cs->lines_col;
		else if ((cs->col == cs->max_col
					|| cs->elem + cs->nb_lastcol < cs->nb_elem - 1)
				&& (cs->elem < cs->nb_elem - 1 || cs->max_col > 0))
		{
			cs->elem -= (cs->max_col / (cs->max_len + 1)) * (cs->lines_col) - 1;
			if (cs->lines_col == 1)
				cs->elem -= 1;
			while (cs->elem < 0)
				cs->elem += cs->lines_col;
		}
		else
			cs->elem = 0;
		if (cs->elem == 0 && cs->scroll > 0 && (cs->scroll = 0) == 0)
			print_col(cs->list, 1);
		else if (cs->row == cs->max_row && cs->scroll < cs->max_scroll
				&& (cs->col == cs->max_col || scroll_nb(cs) > 0)
				&& (cs->scroll += scroll_nb(cs)))
			print_col(cs->list, 1);
		move_cs(&cs);
	}
}

void	arrow_left(t_cs *cs)
{
	if (cs)
	{
		underline_me(cs, 0);
		if (cs->col > cs->min_col)
			cs->elem -= cs->lines_col;
		else if (cs->col == cs->min_col && cs->elem > 0)
		{
			cs->elem += (cs->max_col / (cs->max_len + 1)) * (cs->lines_col) - 1;
			while (cs->elem >= cs->nb_elem)
				cs->elem -= cs->lines_col;
		}
		else if (cs->lines_col <= cs->nb_lastcol || cs->max_col == 0)
			cs->elem = cs->nb_elem - 1;
		else
			cs->elem = cs->nb_elem - 1 - cs->nb_lastcol;
		if (cs->row == cs->min_row && cs->col == cs->min_col
				&& cs->scroll > 0 && (cs->scroll -= 1) >= 0)
			print_col(cs->list, 1);
		else if (cs->scroll == 0 && scroll_nb(cs) > 0 && cs->row == cs->min_row
				&& cs->col == cs->min_col && (cs->scroll += scroll_nb(cs)))
			print_col(cs->list, 1);
		move_cs(&cs);
	}
}

void	space_bar(t_cs *cs)
{
	t_select_lst	*tmp;

	if ((tmp = slct_getlst(cs->list, cs->elem + 1)))
	{
		tmp->is_select = (tmp->is_select ? 0 : 1);
		tputs(tgetstr("me", NULL), 1, &my_putchar);
		cs->elem = (cs->elem == cs->nb_elem - 1 ? 0 : cs->elem + 1);
		if ((cs->elem == 0 || cs->elem % cs->lines_col == 0)
				&& cs->scroll > 0 && (cs->scroll = 0) == 0)
			print_col(cs->list, 1);
		else if (cs->row == cs->max_row && cs->scroll < cs->max_scroll
				&& (cs->col == cs->max_col || scroll_nb(cs) > 0)
				&& (cs->scroll += scroll_nb(cs)))
			print_col(cs->list, 1);
		move_cs(&cs);
	}
}
