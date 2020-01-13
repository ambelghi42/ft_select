NAME = libft.a

# Regular Colors
BLACK = \033[0;30m
RED = \033[0;31m
GREEN = \033[32m
YELLOW = \033[0;33m
BLUE = \033[0;34m
PURPLE = \033[0;35m
CYAN = \033[0;36m
WHITE = \033[0;37m

# Reset
NC = \033[0m

SRCS = ft_atoi.c       \
       ft_bzero.c      \
       ft_countwords.c \
       ft_isalnum.c    \
       ft_isalpha.c    \
       ft_isascii.c    \
       ft_isdigit.c    \
       ft_isprint.c    \
       ft_itoa.c       \
       ft_lstadd.c     \
       ft_lstaddback.c \
       ft_lstdel.c     \
       ft_lstdelone.c  \
       ft_lstiter.c    \
       ft_lstmap.c     \
       ft_lstnew.c     \
       ft_memalloc.c   \
       ft_memccpy.c    \
       ft_memchr.c     \
       ft_memcmp.c     \
       ft_memcpy.c     \
       ft_memdel.c     \
       ft_memmove.c    \
       ft_memset.c     \
       ft_nbrlen.c     \
       ft_putchar.c    \
       ft_putchar_fd.c \
       ft_putendl.c    \
       ft_putendl_fd.c \
       ft_putnbr.c     \
       ft_putnbr_fd.c  \
       ft_putstr.c     \
       ft_putstr_fd.c  \
       ft_strcat.c     \
       ft_strchr.c     \
       ft_strclr.c     \
       ft_strcmp.c     \
       ft_strcpy.c     \
       ft_strdel.c     \
       ft_strdup.c     \
       ft_strequ.c     \
       ft_striter.c    \
       ft_striteri.c   \
       ft_strjoin.c    \
       ft_strlcat.c    \
       ft_strlen.c     \
       ft_strmap.c     \
       ft_strmapi.c    \
       ft_strncat.c    \
       ft_strnchr.c    \
       ft_strncmp.c    \
       ft_strncpy.c    \
       ft_strnequ.c    \
       ft_strnew.c     \
       ft_strnstr.c    \
       ft_strrchr.c    \
       ft_strsplit.c   \
       ft_strstr.c     \
       ft_strsub.c     \
       ft_strtrim.c    \
       ft_tolower.c    \
       ft_toupper.c    \
       ft_d_lstnew.c   \
       ft_d_lstdelone.c \
       ft_d_lstaddback.c \
       ft_d_lstdestroy.c \
       get_next_line.c \
       ft_countoc.c \
       ft_strimoc.c \
       ft_strdchr.c \
       ft_d_lstnew2.c \
       ft_d_lstcount.c \
	   is_strdigit.c \
	   ft_strcheck.c \
	   ft_tabdup.c

#------------------------------------------------------------#

vpath %.c srcs/

PATHO = objs/
PATHS = srcs/
PATHI = includes/


IFLAGS = -I$(PATHI)

CFLAGS = -Wall -Werror -Wextra $(IFLAGS)

OBJS = $(patsubst %.c, $(PATHO)%.o, $(SRCS))

CC = clang

COMPIL = $(CC) -c




all : $(NAME)

$(NAME) : $(PATHO) $(OBJS)
	ar rc $@ $(OBJS)
	ranlib $@
	printf "\t\t\t$(GREEN)$@ is ready.\n$(NC)"

$(OBJS) : $(PATHO)%.o : %.c $(INC)
	$(COMPIL) $(CFLAGS) $< -o $@
	printf "$(ONELINE)$(BLUE)  Compiling $< \n"

$(PATHO) :
	mkdir -p $(PATHO)

clean :
	rm -rf $(PATHO)
	printf "$(RED)Directory obj is  removed\n$(NC)"

fclean : clean
	rm -rf $(NAME)
	printf "$(RED)$(NAME) deleted\n$(NC)"

re : fclean all

norme :
	norminette $(PATHI)
	norminette srcs/

.PHONY: all clean fclean debug
.SILENT:
