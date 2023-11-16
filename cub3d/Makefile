# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: robin <robin@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/16 14:50:47 by ppotier           #+#    #+#              #
#    Updated: 2023/11/15 17:14:28 by robin            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_DIR = srcs

SRC_FILES =	main.c \
			utils.c \
			parsing/parse.c \
			parsing/get_file.c \
			parsing/set_colors.c \
			parsing/set_textures.c \
			parsing/set_map.c \
			parsing/check_map.c \
			parsing/check_surrounding.c \
			game/render_walls.c \
			parsing/map_to_int.c \
			game/key_hooks.c \
			game/game.c \
			game/check_wall.c \
			minimap/draw_mini_map.c \
			minimap/draw_mini_player.c \
			minimap/mini_rayon.c \

SRC = $(addprefix $(SRC_DIR)/,$(SRC_FILES))

CC = gcc

CFLAGS = -Wall -Wextra -Werror

NAME = cub3d

OBJ_DIR = objs
OBJ_FILES = $(SRC_FILES:.c=.o)
OBJ = $(addprefix $(OBJ_DIR)/,$(OBJ_FILES))

all: $(OBJ_DIR) $(NAME)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@
# 	$(CC) $(CFLAGS) -Imlx -I/opt/X11/include -c $< -o $@

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

# Compile tout, sous le nom cud3D
${NAME}:	${LIBFT}	${MLX}		${OBJ}
			${CC}	${OBJ}	$(LIBS) -o  $(NAME)

clean:
	$(RM) -r $(OBJ_DIR)
	$(RM) $(NAME)

fclean: clean
	make fclean -C $(DIR_LIBFT)
	make clean -C $(DIR_MLX)

re:		fclean all

.PHONY: all clean fclean re