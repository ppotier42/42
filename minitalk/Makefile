CFLAGS = -Wall -Werror -Wextra
CC = gcc
CLIENT = client
SERVER = server
INCLUDE = -I minitalk.h
all: $(CLIENT) $(SERVER)

$(CLIENT) : client.c 
		$(CC) $(CFLAGS) $(INCLUDE) client.c utils.c -o client
$(SERVER) : server.c
		$(CC) $(CFLAGS) $(INCLUDE) server.c utils.c -o server

clean :
		rm -rf $(CLIENT) $(SERVER)

fclean:	clean

re: fclean all

