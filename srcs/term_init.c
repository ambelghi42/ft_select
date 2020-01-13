/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   term_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ambelghi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 14:23:13 by ambelghi          #+#    #+#             */
/*   Updated: 2020/01/13 14:34:53 by ambelghi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <termios.h>
#include <term.h>
#include "ft_select.h"
#include <unistd.h>
#include <sys/ioctl.h>
#include <fcntl.h>
#include <stdlib.h>

void	set_term(int tty, int init, char **av)
{
	t_select_lst	*list;
	struct termios	new_term;
	t_cs			*cs;

	if (init == 1)
		list = params_tolist(av);
	new_term.c_lflag &= ~(ICANON);
	new_term.c_lflag &= ~ECHO;
	new_term.c_cc[VMIN] = 1;
	new_term.c_cc[VTIME] = 0;
	tcsetattr(tty, TCSANOW, &new_term);
	if (init == 1)
		cs_master(list, 1);
	cs = cs_master(NULL, 0);
	cs_set(cs->list, cs->max_len);
	if (init == 2 && cs)
		get_cs_position(&cs->min_col, &cs->min_row);
	cs->min_col = 0;
	cs_set(cs->list, cs->max_len);
	cs->tty = tty;
	cs->av = av;
	tputs(tgetstr("vi", NULL), 1, &my_putchar);
	print_col(cs->list, 0);
	move_cs(&cs);
}

void	unset_term(struct termios *old_term)
{
	t_cs	*cs;

	if ((cs = cs_master(NULL, 0)))
	{
		ft_clear();
		tputs(tgoto(tgetstr("cm", NULL), cs->min_col, cs->min_row),
				1, &my_putchar);
		tputs(tgetstr("ve", NULL), 1, &my_putchar);
		tcsetattr(cs->tty, 0, old_term);
	}
}

int		term_init(int init, char **av)
{
	struct termios			new_term;
	static struct termios	old_term = {0};
	int						tty;

	tty = ttyslot();
	signal(SIGWINCH, &size_handler);
	signal(SIGCONT, &pause_handler);
	signal(SIGINT, &sig_handler);
	if (init >= 1 && isatty(tty) && getenv("TERM")
			&& tgetent(NULL, getenv("TERM")) == 1)
	{
		if (init >= 1 && (tcgetattr(tty, &old_term) == -1
					|| tcgetattr(tty, &new_term) == -1))
			return (0);
		set_term(tty, init, av);
		return (1);
	}
	if (init == 0)
	{
		unset_term(&old_term);
		return (1);
	}
	return (0);
}
