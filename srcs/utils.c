/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ambelghi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 14:31:14 by ambelghi          #+#    #+#             */
/*   Updated: 2020/01/13 16:44:00 by ambelghi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_select.h"
#include "libft.h"

int		my_putchar(int c)
{
	ft_putchar_fd((char)c, ttyslot());
	return (1);
}

void	get_cs_position(int *col, int *rows)
{
	char	buf[5];
	int		i;
	int		a;

	a = 0;
	i = 0;
	write(ttyslot(), "\033[6n", 4);
	read(ttyslot(), buf, 4);
	buf[4] = '\0';
	while (buf[i])
	{
		if (buf[i] >= 48 && buf[i] <= 57)
		{
			if (a == 0)
				*rows = ft_atoi(&buf[i]) - 1;
			else
				*col = ft_atoi(&buf[i]) - 1;
			a++;
		}
		i++;
	}
}

int		get_maxlen(t_select_lst *list)
{
	t_select_lst	*tmp;
	int				max_len;
	int				ncol;

	max_len = 0;
	ncol = 0;
	if ((tmp = list))
	{
		while ((tmp = tmp->next))
		{
			if ((ncol = ft_strlen(tmp->name)) > max_len)
				max_len = ncol;
		}
	}
	return (max_len);
}

void	putchar_n(char c, int n)
{
	t_cs	*cs;

	cs = cs_master(NULL, 0);
	while (n-- > 0)
		write(cs->tty, &c, 1);
}

int		get_nbmax(t_cs *cs)
{
	int	nb_max;

	nb_max = 1;
	if (cs)
	{
		nb_max = cs->scroll
			* (cs->max_col / (cs->max_len + 1) + 1)
			+ (cs->lines_col * (cs->max_col / (cs->max_len + 1) + 1)
					- cs->max_scroll - 1);
		nb_max = (nb_max > cs->nb_elem ? cs->nb_elem : nb_max);
	}
	return (nb_max);
}
