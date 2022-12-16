# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ppotier <ppotier@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/16 14:50:47 by ppotier           #+#    #+#              #
#    Updated: 2022/12/16 16:19:31 by ppotier          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = main.c 

CC = gcc

CFLAGS = -Wall -Werror -Wextra

NAME = so_long

OBJ = $(SRC:.c=.o)

all: $(NAME)

.c .o:
		$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

RM = rm -f


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

${NAME}:	${MLX} 	${OBJ}
			${CC}	${OBJ} -o ${NAME}

clean:
		$(RM) $(OBJ)

fclean:	clean
		$(RM) $(NAME)

re:		fclean all