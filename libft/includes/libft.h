/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ambelghi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 14:02:01 by ambelghi          #+#    #+#             */
/*   Updated: 2020/01/13 17:38:33 by ambelghi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct	s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}				t_list;

typedef struct	s_double_list
{
	void					*content;
	size_t					content_size;
	struct s_double_list	*next;
	struct s_double_list	*prev;
}				t_double_list;

void			*ft_memalloc(size_t size);
void			ft_memdel(void **ap);
char			*ft_strnew(size_t size);
void			ft_strdel(char **as);
void			ft_strclr(char *s);
void			ft_striter(char *s, void (*f)(char *));
void			ft_striteri(char *s, void (*f)(unsigned int, char *));
char			*ft_strmap(char const *s, char (*f)(char));
char			*ft_strmapi(char const *s, char(*f)(unsigned int, char));
int				ft_strequ(char const *s1, char const *s2);
int				ft_strnequ(char const *s1, char const *s2, size_t n);
char			*ft_strsub(char const *s, unsigned int start, size_t len);
int				ft_strlen(char const *s);
void			ft_putstr(char const *s);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strtrim(char const *s);
char			**ft_strsplit(char const *s, char *c);
int				ft_countwords(char const *s, char *c);
int				ft_nbrlen(int n);
char			*ft_itoa(int n);
void			ft_putchar(char c);
void			ft_putendl(char const *s);
void			ft_putnbr(int n);
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char const *s, int fd);
void			ft_putendl_fd(char const *s, int fd);
void			ft_putnbr_fd(int n, int fd);
void			*ft_memset(void *b, int c, size_t len);
void			ft_bzero(void *s, size_t n);
void			*ft_memcpy(void *dst, const void *src, size_t n);
void			*ft_memccpy(void *dst, const void *src, int c, size_t n);
void			*ft_memmove(void *dst, void const *src, size_t len);
void			*ft_memchr(const void *s, int c, size_t n);
int				ft_memcmp(void const *s1, void const *s2, size_t n);
char			*ft_strdup(char const *s);
char			*ft_strcpy(char *dst, char const *src);
char			*ft_strncpy(char *dst, char const *src, size_t len);
char			*ft_strcat(char *s1, char const *s2);
char			*ft_strncat(char *s1, char const *s2, size_t n);
size_t			ft_strlcat(char *s1, char const *s2, size_t size);
char			*ft_strchr(char const *s, int c);
char			*ft_strrchr(char const *s, int c);
char			*ft_strstr(char const *s1, char const *s2);
char			*ft_strnstr(char const *s1, char const *s2, size_t len);
char			*ft_strnchr(char const *s, int c, size_t len);
int				ft_strcmp(char const *s1, char const *s2);
int				ft_strncmp(char const *s1, char const *s2, size_t n);
int				ft_atoi(char const *str);
int				ft_isalpha(int c);
int				ft_isalpha(int c);
int				ft_isdigit(int c);
int				ft_isalnum(int c);
int				ft_isascii(int c);
int				ft_toupper(int c);
int				ft_tolower(int c);
int				ft_isprint(int c);
t_list			*ft_lstnew(void const *content, size_t content_size);
void			ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void			ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void			ft_lstadd(t_list **alst, t_list *new);
void			ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
void			ft_lstaddback(t_list **alst, t_list *new);
t_double_list	*ft_d_lstnew(void const *content, size_t content_size);
void			ft_d_lstaddback(t_double_list **alst, t_double_list *new);
void			ft_d_lstdelone(t_double_list **alst);
void			ft_d_lstdestroy(t_double_list **begin);
int				get_next_line(int fd, char **line);
int				ft_countoc(char *s, char oc);
char			*ft_strimoc(char const *s, char oc);
char			*ft_strdchr(char const *s, int c);
t_double_list	*ft_d_lstnew2(void *content);
int				ft_d_lstcount(t_double_list *elem);
char			**ft_tabdup(char **tabew);
int				is_strdigit(char *s);
int				ft_strcheck(char const *s, char *oc);

#endif
