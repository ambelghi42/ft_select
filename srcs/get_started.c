/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_started.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ambelghi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 17:01:55 by ambelghi          #+#    #+#             */
/*   Updated: 2020/01/13 14:32:05 by ambelghi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <termios.h>
#include <term.h>
#include <sys/ioctl.h>
#include <fcntl.h>
#include "ft_select.h"
#include <time.h>

void	h_scroll(t_cs *cs)
{
	static int		tmp = 0;
	t_select_lst	*lst;

	if (cs)
	{
		if (tmp - (clock() / (CLOCKS_PER_SEC / 4)) > 1
				&& (lst = slct_getlst(cs->list, cs->elem + 1))
				&& ft_strlen(lst->name) > cs->screen.x)
		{
			tmp = (clock() / (CLOCKS_PER_SEC / 4));
			if (cs->h_scroll < cs->max_hscroll)
				cs->h_scroll += 1;
			else
				cs->h_scroll = 0;
			move_cs(&cs);
		}
	}
}

void	read_input(void)
{
	int		len;
	int		stop;
	char	*buf;
	t_cs	*cs;

	stop = 0;
	len = 0;
	cs = cs_master(NULL, 0);
	underline_me(cs, 1);
	while (stop >= 0)
	{
		ioctl(STDIN_FILENO, FIONREAD, &len);
		h_scroll(cs);
		if (len <= 0)
			continue ;
		if (!(buf = ft_strnew(len + 1)))
			break ;
		if (read(STDIN_FILENO, buf, len) != len)
			stop = -1;
		stop = (stop >= 0 ? check_keys(buf) : stop);
		ft_strdel(&buf);
	}
}

void	ft_clear(void)
{
	t_point			col;
	t_cs			*cs;
	struct winsize	ws;

	if ((cs = cs_master(NULL, 0)))
	{
		col.x = cs->min_col;
		col.y = cs->min_row;
		ioctl(0, TIOCGWINSZ, &ws);
		tputs(tgoto(tgetstr("cm", NULL), cs->min_col, cs->min_row),
				1, &my_putchar);
		while (col.y++ <= ws.ws_row)
			tputs(tgetstr("dl", NULL), ws.ws_col, &my_putchar);
		tputs(tgoto(tgetstr("cm", NULL), cs->min_col, cs->min_row),
				1, &my_putchar);
	}
}

int		main(int ac, char **av)
{
	t_cs	*cs;

	if (ac > 1 && term_init(1, av) == 1)
	{
		cs = cs_master(NULL, 0);
		read_input();
		slct_lstfree(&cs->list);
		term_init(0, av);
		if (cs->ret)
			ft_putstr_fd(cs->ret, 1);
		ft_strdel(&(cs->ret));
	}
	exit(0);
}
