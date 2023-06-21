# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ppotier <ppotier@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/16 14:50:47 by ppotier           #+#    #+#              #
#    Updated: 2023/06/21 13:43:44 by ppotier          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = 	main.c \
		utilis.c \
		check_args.c \
		one_philo.c \
		routine.c \

CC = gcc

CFLAGS = -Wall -Wextra -Werror -pthread

NAME = philo

OBJ = $(SRC:.c=.o)

all: $(NAME)

.c .o:
		$(CC) -c $< -o $(<:.c=.o)

RM = rm -f

# Compile tout, sous le nom philo
${NAME}:	${OBJ}
			${CC} ${CFLAGS} ${OBJ} -o ${NAME}

clean:	
		$(RM) $(OBJ) $(NAME)

fclean:	clean
		$(RM) $(NAME)

re:		fclean all
