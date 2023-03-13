SERVER_SRC = server.c 
CLIENT_SRC = client.c 
HEADERS = minitalk.h
CC = gcc -Wall -Wextra -Werror
LIB = = -L libft -lft

.c .o:	$(HEADERS) libft/libft.a 
		$(CC) $< -c -o $(<:.c=.o)


libft : 
		@make -C libft

server :	$(SERVER_SRC:.c=.o) $(HEADERS)
			(CC) $(SERVER_SRC) $(LIB) -o server

client : 	$(CLIENT_SRC:.c=.o) $(HEADERS)
			(CC) $(CLIENT_SRC) $(LIB) -o client

all: libft server client

clean : 
		rm -rf ${SERVER_SRC:.c=.o} ${CLIENT_SRCS:.c=.o}
		@make clean -C libft

fclean : clean
		rm -rf server client
		@make fclean -C libft

re : 	fclean all

.PHONY:	all clean fclean re
