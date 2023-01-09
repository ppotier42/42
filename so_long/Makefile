# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ppotier <ppotier@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/16 14:50:47 by ppotier           #+#    #+#              #
#    Updated: 2023/01/09 15:13:00 by ppotier          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = 	main.c \

CC = gcc

CFLAGS = -Wall -Werror -Wextra

NAME = so_long

OBJ = $(SRC:.c=.o)

all: $(NAME)

.c .o:
		$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

RM = rm -f

# Compile ft_printf
DIR_PRINTF = ft_printf/
PRINTF_INC = -I $(DIR_PRINTF)
PRINTF = $(DIR_PRINTF) libftprintf.a
PRINTLINK = -L $(DIR_PRINTF) -l

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
LIBS = $(FT_LINK)	$(PRINTLINK)	$(MLX_LNK)		
# Make la lib
$(LIBFT):
		$(MAKE) -sC $(@D)
# Make ft_printf
$(PRINTF):
		$(MAKE) -sC $(@D)
# Make la mlx
$(MLX):
		$(MAKE) -sC $(@D)

# Compile tout, sous le nom so_long
${NAME}:	$(PRINTF)	${LIBFT}	${MLX}		${OBJ}
			${CC}	${OBJ}	$(LIBS) -o ${NAME}

clean:	
		$(RM) $(OBJ)
		make fclean -C ./libft
		make fclean -C ./ft_printf
		make clean -C ./mlxOS

fclean:	clean
		$(RM) $(NAME)

re:		fclean all

.PHONY: all clean fclean re