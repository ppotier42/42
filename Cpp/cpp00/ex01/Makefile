# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ppotier <ppotier@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/11 14:38:43 by ppotier           #+#    #+#              #
#    Updated: 2023/09/28 17:18:49 by ppotier          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =	Phonebook
CC =	c++
CFLAGS = -Wall -Wextra -Werror -std=c++98
RM = rm -rf

SRCS =	Phonebook.cpp \
		Contact.cpp \

OBJDIR = objs

OBJS = $(addprefix $(OBJDIR)/, $(SRCS:.cpp=.o))

GREEN		=	\e[92;5;118m

all : $(NAME)

%.o : %.cpp Makefile
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME) : $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	@printf "$(GREEN) Executable Ready\n"

$(OBJDIR)/%.o: %.cpp
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@

clean : 
	$(RM) $(OBJDIR) $(OBJS)

fclean : clean
	$(RM) $(NAME)

re : fclean all

phony : re all clean flcean
