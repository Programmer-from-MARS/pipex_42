NAME = pipex

NAME_B = pipex_bonus

NAME_LIB = libft.a

LIST_LIB = ./libft/

LIB = -L ./libft -lft

MAN = ./mandatory/

LIST =	$(MAN)extract_cmd.c\
		$(MAN)initialize_struct.c\
		$(MAN)main.c\
		$(MAN)pipex.c\
		$(MAN)utils.c\

BON = ./bonus/

LIST_B =	$(BON)extract_cmd_bonus.c\
			$(BON)initialize_struct_bonus.c\
			$(BON)main_bonus.c\
			$(BON)pipex_bonus.c\
			$(BON)utils_bonus.c\

CC = gcc

OBJS = $(LIST:.c=.o)

OBJS_B = $(LIST_B:.c=.o)

HEADER = $(MAN)pipex.h

HEADER_B = $(BON)pipex_bonus.h

HEADER_LIB = libft.h

CFLAGS = -Wall -Werror -Wextra

MAKE = make -C $(LIST_LIB)

all: $(NAME)

$(NAME): $(HEADER) $(OBJS) $(LIST)
		make -C $(LIST_LIB)
		$(CC) $(CFLAGS) $(OBJS) $(LIB) -o $@

$(NAME_B): $(HEADER_B) $(OBJS_B) $(LIST_B)
		make -C $(LIST_LIB)
		$(CC) $(CFLAGS) $(OBJS) $(LIB) -o $@

bonus:		$(NAME_B)

clean: 
	@rm -f *.out
	@rm -f *.o
	@rm -f $(OBJS) $(OBJS_B)
	make clean -C $(LIST_LIB)

fclean:	clean
	@rm -f $(NAME) $(NAME_B)
	make fclean -C $(LIST_LIB)

re: fclean all

.PHONY: all clean fclean re bonus