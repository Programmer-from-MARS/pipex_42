NAME = libft.a

LIST =	ft_strnstr.c\
		ft_strjoin.c\
		ft_split.c\
		ft_putstr_fd.c\
		ft_putchar_fd.c\
		ft_strlen.c\

OBJS = $(LIST:.c=.o)

FLAGS = -Wall -Werror -Wextra

OBJ = $(OBJS)

all : $(NAME)

$(NAME) : $(OBJ) libft.h
	ar rcs $(NAME) $?

clean: 
	@rm -f $(OBJS)

fclean:	clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re