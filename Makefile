# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ambelghi <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/13 14:50:28 by ambelghi          #+#    #+#              #
#    Updated: 2020/01/13 17:52:46 by ambelghi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_select

# Reset
NC=\033[0m

# Regular Colors
BLACK=\033[0;30m
RED=\033[0;31m
GREEN =\033[32m
YELLOW=\033[0;33m
BLUE=\033[0;34m
PURPLE=\033[0;35m
CYAN=\033[0;36m
WHITE=\033[0;37m

CC = Clang
COMPILE = $(CC) -c

MKDIR = mkdir -p
CLEANUP = rm -rf

WFLAGS = -Wall -Werror -Wextra
IFLAGS = -I$(IPATH) -I$(LIPATH)
CFLAGS = $(WFLAGS) $(IFLAGS)
DEBUG = $(CFLAGS) -g

PATHO = obj/
SPATH = srcs/
IPATH = includes/
LPATH = libft/
LIPATH = libft/includes
LIB = $(LPATH)libft.a

INCS += minishell.h

SRCS += get_started.c
SRCS += columns.c
SRCS += keys.c
SRCS += keys2.c
SRCS += list.c
SRCS += list2.c
SRCS += print.c
SRCS += signals.c
SRCS += term_init.c
SRCS += utils.c
SRCS += cursor.c


OBJS = $(patsubst %.c, $(PATHO)%.o, $(SRCS))


all : $(NAME)

$(NAME) : $(LIB) $(PATHO) $(OBJS)
	$(CC) -lncurses -o $@ $< $(OBJS)
	printf "$(GREEN)$@ is ready.\n$(NC)"

$(OBJS) : $(PATHO)%.o : $(SPATH)%.c
	$(COMPILE) $(CFLAGS) $< -o $@

$(PATHO) :
	$(MKDIR) $@

$(LIB) :
	$(MAKE) -C $(LPATH)

clean :
	$(MAKE) -C $(LPATH) clean
	$(CLEANUP) $(OBJS)
	$(CLEANUP) $(PATHO)

fclean : clean
	$(MAKE) -C $(LPATH) fclean
	$(CLEANUP) $(PATHO)
	$(CLEANUP) $(NAME)

re : fclean all

norme:
	norminette srcs
	norminette includes
	norminette libft/srcs
	norminette libft/includes

.PHONY: all clean fclean norme re
