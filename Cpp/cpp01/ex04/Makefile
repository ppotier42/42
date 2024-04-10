NAME = sed
CC =	c++
CFLAGS = -Wall -Wextra -Werror -std=c++98
RM = rm -rf

SRCS =	main.cpp \

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
	@$(CC) $(FLAGS) -c $< -o $@

clean :
	$(RM) $(OBJDIR) $(OBJS)
	$(RM) *.replace

fclean : clean
	$(RM) $(NAME)

re : fclean all
