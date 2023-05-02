# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ppotier <ppotier@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/16 14:50:47 by ppotier           #+#    #+#              #
#    Updated: 2023/05/02 13:11:29 by ppotier          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = main.c \
		
CC = gcc

CFLAGS = -Wall -Wextra -Werror

NAME = philo

OBJ = $(SRC:.c=.o)

all: $(NAME)

.c .o:
		$(CC) -c $< -o $(<:.c=.o)

RM = rm -f

# Compile tout, sous le nom philo
${NAME}:	${OBJ}
			${CC}	${OBJ}	$(LIBS) -o ${NAME}

clean:	
		$(RM) $(OBJ) $(NAME)
fclean:	clean

		$(RM) $(NAME)

re:		fclean all
