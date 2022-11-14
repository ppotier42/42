CC = gcc

CFLAGS = -Wall -Werror -Wextra

OBJ = $(SRC:.c=.o)

NAME = libftprintf.a

AR = ar rcs

SRC = 	ft_printf.c \

all: $(NAME)

$(NAME):	$(OBJ)
			make bonus -C ./libft 
			cp ../libft/libft.h $(NAME)
			$(AR) $(NAME) $(OBJ)

.c .o:
		$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

RM = rm -f

clean:
		$(RM) $(OBJ)

fclean:	clean
		$(RM) $(NAME)

re:		fclean all

.PHONY:	all clean fclean re bonus