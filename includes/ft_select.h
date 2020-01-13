/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ambelghi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 20:47:25 by ambelghi          #+#    #+#             */
/*   Updated: 2020/01/13 16:36:12 by ambelghi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SELECT_H
# define FT_SELECT_H

# include <sys/ioctl.h>
# include <fcntl.h>
# include <termios.h>
# include <term.h>

typedef struct	s_point
{
	int x;
	int y;
}				t_point;

typedef struct	s_select_lst
{
	struct s_select_lst	*prev;
	struct s_select_lst	*next;
	char				*name;
	int					i;
	int					is_select;
}				t_select_lst;

typedef struct	s_cs
{
	int				col;
	int				row;
	int				min_col;
	int				min_row;
	int				max_col;
	int				max_row;
	int				max_len;
	int				nb_elem;
	int				elem;
	int				scroll;
	int				max_scroll;
	int				lines_col;
	int				nb_lastcol;
	int				h_scroll;
	int				max_hscroll;
	int				tty;
	char			**av;
	char			*ret;
	t_point			screen;
	t_select_lst	*list;
}				t_cs;

t_cs			*cs_master(t_select_lst *list, int init);
void			space_bar(t_cs *cs);
int				check_keys(char *caps);
void			arrow_up(t_cs *cs);
void			arrow_down(t_cs *cs);
void			arrow_right(t_cs *cs);
void			arrow_left(t_cs *cs);
int				my_putchar(int c);
void			get_cs_position(int *col, int *rows);
void			read_input(void);
void			print_col(t_select_lst *list, int print_params);
t_select_lst	*params_tolist(char **env);
int				slct_listcount(t_select_lst *elem);
t_select_lst	*slct_lstnew(char *var, int i, int is_select);
void			slct_lstaddb(t_select_lst *start, t_select_lst *new);
void			slct_lstdelone(t_select_lst **lst);
void			slct_lstfree(t_select_lst **lst);
t_select_lst	*slct_dup(t_select_lst *list);
t_select_lst	*slct_getlst(t_select_lst *list, int n);
void			print_line(t_select_lst *tmp, t_point max, int elem);
int				get_maxlen(t_select_lst *list);
void			cs_set(t_select_lst *list, int max_len);
void			ft_clear(void);
void			underline_me(t_cs *cs, int ue);
int				scroll_nb(t_cs *cs);
void			move_cs(t_cs **cs);
void			print_name(t_select_lst *lst, t_cs *cs);
int				term_init(int init, char **av);
void			size_handler(int sig);
void			pause_handler(int sig);
void			sig_handler(int sig);
void			cs_setter(int nb_elem, int max_col, t_cs *cs,
							struct winsize size);
void			print_hscroll(t_select_lst *list, t_cs *cs);
void			start_colors(t_select_lst *lst, int ue);
void			end_colors(t_select_lst *lst, int ue);
void			cs_moveme(t_point *ew, t_cs *tmp);
void			print_colme(t_select_lst *tmp, t_point max, t_cs *cs);
void			print_colmvcs(int scroll, t_point tmp_col, t_cs *cs);
void			putchar_n(char c, int n);

#endif
