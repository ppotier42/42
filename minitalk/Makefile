SERVER_SRCS = server.c 
CLIENT_SRCS = client.c 
HEADERS = minitalk.h
CC = gcc -Wall -Wextra -Werror
LIB = = -L libft -lft

.c .o:	$(HEADERS) libft/libft.a 
		$(CC) $< -c -o $(<:.c=.o)

all: libft server client

libft : 
		@make -C libft

server :	$(SERVER_SRCS:.c=.o) $(HEADERS)
			(CC) $(SERVER_SRCS) $(LIB) -o server

client : 	$(CLIENT_SRCS:.c=.o) $(HEADERS)
			(CC) $(CLIENT_SRCS) $(LIB) -o client


clean : 
		rm -rf ${SERVER_SRCS:.c=.o} ${CLIENT_SRCS:.c=.o}
		@make clean -C libft

fclean : clean
		rm -rf server client
		@make fclean -C libft

re : 	fclean all

.PHONY:	all clean fclean re
