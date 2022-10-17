# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ppotier <pierre.podnieks@gmail.com>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/11 11:44:54 by ppotier           #+#    #+#              #
#    Updated: 2022/10/17 17:59:33 by ppotier          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = gcc
CFLAGS = -Wall -Werror -Wextra

SOURCE = ft_atoi.c ft_bzero.c ft_isalnum.c ft_isalpha.c ft_isascii.c \
		ft_isdigit.c ft_isprint.c ft_memchr.c ft_memcmp.c ft_memcpy.c \
		ft_memcpy.c ft_memmove.c ft_memset.c ft_putchar_fd.c \
		ft_putendl_fd.c ft_putstr_fd.c ft_strchr.c ft_strjoin.c \
		ft_strlcat.c ft_strlen.c ft_strncmp.c  ft_strrchr.c \
		ft_tolower.c ft_toupper.c \

OBJ = $(SOURCE: .c=.o)
RM = rm -f
all: $(NAME)

$(NAME): $(OBJ)
			ar rcs $(NAME) $(OBJS)
		
clean:
				$(RM) $(OBJS)

fclean:			clean
				$(RM) $(NAME)
re:				fclean $(NAME)

.PHONY:			all clean fclean re bonus