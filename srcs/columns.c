/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   columns.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ambelghi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/23 14:18:14 by ambelghi          #+#    #+#             */
/*   Updated: 2020/01/13 17:01:01 by ambelghi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"
#include "libft.h"
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/ioctl.h>
#include <term.h>

void	print_line(t_select_lst *tmp, t_point max, int elem)
{
	t_select_lst	*tmp2;
	t_point			i;
	int				spaces;
	t_cs			*cs;

	i.x = 0;
	tmp2 = tmp;
	cs = cs_master(tmp, 0);
	while (tmp2 && tmp2->next && i.x++ < elem)
		tmp2 = tmp2->next;
	i.x = 0;
	while (tmp2 && (spaces = max.x) >= 0 && ++i.x)
	{
		i.y = 0;
		while (i.x - 1 > 0 && i.y++ < max.y && tmp2)
			tmp2 = tmp2->next;
		if (tmp2 && (spaces = spaces - ft_strlen(tmp2->name) + 1) >= 0)
		{
			start_colors(tmp2, 0);
			print_name(tmp2, cs);
			end_colors(tmp2, 0);
			while (cs->max_len + 1 < cs->screen.x && spaces-- > 0)
				ft_putchar_fd(' ', cs->tty);
		}
	}
}

void	print_col(t_select_lst *list, int scroll)
{
	t_point			max;
	t_point			tmp_col;
	t_select_lst	*tmp;
	t_cs			*cs;
	struct winsize	ws;

	if ((tmp = list))
	{
		ioctl(0, TIOCGWINSZ, &ws);
		max.x = get_maxlen(list);
		cs_set(list, max.x);
		ft_clear();
		if ((cs = cs_master(NULL, 0)))
		{
			max.y = cs->lines_col;
			tputs(tgoto(tgetstr("cm", NULL), cs->min_col,
						cs->min_row), 1, &my_putchar);
			tmp_col.x = cs->col;
			tmp_col.y = cs->row;
			cs->col = cs->min_col;
			cs->row = cs->min_row;
			print_colme(tmp, max, cs);
			print_colmvcs(scroll, tmp_col, cs);
		}
	}
}

void	print_colme(t_select_lst *tmp, t_point max, t_cs *cs)
{
	int				i;
	struct winsize	ws;

	i = 0;
	ioctl(0, TIOCGWINSZ, &ws);
	while ((tmp = tmp->next) && i++ < max.y - cs->max_scroll)
	{
		if (i <= max.y && cs->row >= ws.ws_row && cs->min_row != 0)
		{
			tputs(tgetstr("sf", NULL), 1, &my_putchar);
			print_line(tmp, max, cs->scroll);
			cs->min_row += -1;
			tputs(tgoto(tgetstr("cm", NULL), cs->min_col,
						cs->row), 1, &my_putchar);
		}
		else
		{
			print_line(tmp, max, cs->scroll);
			cs->row += 1;
		}
		tputs(tgoto(tgetstr("cm", NULL), cs->min_col,
					cs->row), 1, &my_putchar);
	}
}

void	print_colmvcs(int scroll, t_point tmp_col, t_cs *cs)
{
	if (scroll == 0 && (cs->col = cs->min_col) >= 0)
		cs->row = cs->min_row;
	else if ((cs->row = tmp_col.y) >= 0)
		cs->col = tmp_col.x;
	tputs(tgoto(tgetstr("cm", NULL), cs->col,
				cs->row), 1, &my_putchar);
}
