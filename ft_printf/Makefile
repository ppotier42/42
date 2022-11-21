SRC = 	ft_printf.c \
		ft_add.c \
		ft_nbrlen.c

CC = gcc

CFLAGS = -Wall -Werror -Wextra

OBJ = $(SRC:.c=.o)

NAME = libftprintf.a

RM = rm -f

.c .o:
		$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

all: $(NAME)

$(NAME):	$(OBJ)
			make bonus -C ../libft
			mv ../libft/libft.a $(NAME)
			ar rcs $(NAME) $(OBJ)

clean:	
		make fclean -C ../libft
		$(RM) $(OBJ)

fclean:	clean
		$(RM) $(NAME)

re:		fclean all

.PHONY:	all clean fclean re bonus
