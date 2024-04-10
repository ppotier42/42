NAME = Hermes
CC =	c++
CFLAGS = -Wall -Wextra -Werror -std=c++98
RM = rm -rf

SRCS = 	main.cpp \
		Bureaucrat.cpp \
		Form.cpp \
		PresidentialPardonForm.cpp \
		RobotomyRequestForm.cpp \
		ShrubberyCreationForm.cpp \
		Intern.cpp \

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
	$(RM) shrub_shruberry

fclean : clean
	$(RM) $(NAME)

re : fclean all

phony : re all clean flcean