# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ppotier <ppotier@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/16 14:50:47 by ppotier           #+#    #+#              #
#    Updated: 2022/12/16 21:56:52 by ppotier          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = 	events.c \

CC = gcc

CFLAGS = -Wall -Werror -Wextra

NAME = so_long

OBJ = $(SRC:.c=.o)

all: $(NAME)

.c .o:
		$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

RM = rm -f

# Compile la lib
DIR_LIBFT = libft/
LIBFT_INC = -I $(DIR_LIBFT)
LIBFT = $(DIR_LIBFT)libft.a
FT_LINK = -L $(DIR_LIBFT) -l ft

# Compile la MiniLibX suivant l'OS
ifeq (${shell uname}, Linux)
        DIR_MLX = mlx_linux/
        MLX_LNK = -L $(DIR_MLX) -lmlx -lXext -lX11 -lbsd
else
        DIR_MLX = mlxOS/
        MLX_LNK = -L $(DIR_MLX) -l mlx -framework OpenGL -framework AppKit
endif

MLX_INC = -I ${DIR_MLX}
MLX =   ${DIR_MLX}libmlx.a

LIBS = $(FT_LINK)	$(MLX_LNK)

${NAME}:	${LIBFT}	${MLX} 	${OBJ}
			${CC}	${OBJ}	$(LIBS) -o ${NAME}

clean:
		$(RM) $(OBJ)

fclean:	clean
		$(RM) $(NAME)

re:		fclean all