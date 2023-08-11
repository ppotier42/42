# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ppotier <ppotier@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/16 14:50:47 by ppotier           #+#    #+#              #
#    Updated: 2023/08/07 18:05:56 by ppotier          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC =	srcs/main.c \
		srcs/get_data.c \
		srcs/draw_line.c \
		srcs/transition.c \
		srcs/key_hook.c \

CC = gcc

CFLAGS = -Wall -Wextra -Werror

NAME = fdf

OBJ = $(SRC:.c=.o)

all: $(NAME)

.c .o:
		$(CC) -c $< -o $(<:.c=.o)

RM = rm -f

# Compile la lib
DIR_LIBFT = libft/
LIBFT_INC = -I $(DIR_LIBFT)
LIBFT = $(DIR_LIBFT)libft.a
FT_LINK = -L $(DIR_LIBFT) -l ft

# Compile la MiniLBX
DIR_MLX = mlxOS/
MLX_LNK = -L $(DIR_MLX) -l mlx -framework OpenGL -framework AppKit
MLX_INC = -I ${DIR_MLX}
MLX =   ${DIR_MLX}libmlx.a

# Link la lib, la mlx et ft_printf
LIBS = $(FT_LINK)	$(MLX_LNK)		

# Make la lib
$(LIBFT):
		$(MAKE) -sC $(@D)

# Make la mlx
$(MLX):
		$(MAKE) -sC $(@D)

# Compile tout, sous le nom fdf
${NAME}:	${LIBFT}	${MLX}		${OBJ}
			${CC}	${OBJ}	$(LIBS) -o ${NAME}

clean:	
		$(RM) $(OBJ)
		make fclean -C ./libft
		make clean -C ./mlxOS

fclean:	clean
		$(RM) $(NAME)

re:		fclean all

.PHONY: all clean fclean re