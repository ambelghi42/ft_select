/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ambelghi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/05 21:23:07 by ambelghi          #+#    #+#             */
/*   Updated: 2019/07/07 22:49:18 by ambelghi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	**check_fd(int fd, int delete)
{
	static t_double_list	*begin = NULL;
	t_double_list			**tmp_list;

	tmp_list = &begin;
	if (*tmp_list)
	{
		while ((*tmp_list)->next && (*tmp_list)->content_size != (size_t)fd)
			tmp_list = &(*tmp_list)->next;
		if (delete == 1)
			ft_d_lstdelone(tmp_list);
		if (*tmp_list && (*tmp_list)->content_size != (size_t)fd)
		{
			ft_d_lstaddback(&begin, ft_d_lstnew("", fd));
			tmp_list = &(*tmp_list)->next;
		}
		return (*tmp_list ? (char **)&(*tmp_list)->content : NULL);
	}
	else
	{
		begin = ft_d_lstnew("", fd);
		return (begin ? (char**)&begin->content : NULL);
	}
}

int		ft_split(char **stat_buff, char **line, int fd)
{
	char	*oc;
	char	*tmp;

	if (stat_buff && *stat_buff)
	{
		tmp = *stat_buff;
		if ((oc = ft_strchr(*stat_buff, '\n')))
		{
			*stat_buff = ft_strdup(oc + 1);
			*oc = '\0';
		}
		if (oc || *tmp)
		{
			*line = ft_strdup(tmp);
			if (*stat_buff && !oc)
				ft_memdel((void **)stat_buff);
			else
				ft_memdel((void **)&tmp);
			return (1);
		}
	}
	check_fd(fd, 1);
	return (0);
}

int		get_next_line(int fd, char **line)
{
	char	*oc;
	char	buff[BUFF_SIZE + 1];
	char	**stat_line;
	int		ret;

	if (fd < 0 || !line || BUFF_SIZE <= 0 || read(fd, buff, 0) < 0)
		return (-1);
	if (!(stat_line = check_fd(fd + 1, 0)))
		return (-1);
	while ((ret = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[ret] = '\0';
		oc = *stat_line;
		*stat_line = (char *)ft_strjoin(*stat_line, buff);
		ft_strdel(&oc);
		if ((oc = ft_strchr(*stat_line, '\n')))
			break ;
	}
	return (ret < 0 ? -1 : ft_split(stat_line, line, fd));
}
