CFLAGS = -Wall -Werror -Wextra
CC = gcc
CLIENT = client
SERVER = server

all: $(CLIENT) $(SERVER)

$(CLIENT) : client.c 
		$(CC) $(CFLAGS) client.c utils.c -o client
$(SERVER) : server.c
		$(CC) $(CFLAGS) server.c utils.c -o server

clean :
		rm -rf $(CLIENT) $(SERVER)

fclean:	clean

re: fclean all

