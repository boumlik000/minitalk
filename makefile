CFLAGS = -Wall -Werror -Wextra
CC = cc

CLIENT = client
SERVER = server
CLIENT_BONUS = client_bonus
SERVER_BONUS = server_bonus

SRC = utilities.c

OBJC =  $(CLIENT:=.o) $(SRC:.c=.o)
OBJS =  $(SERVER:=.o) $(SRC:.c=.o)
OBJCB =  $(CLIENT_BONUS:=.o) $(SRC:.c=.o)
OBJSB =  $(SERVER_BONUS:=.o) $(SRC:.c=.o)

all: $(CLIENT) $(SERVER)
$(CLIENT) : client.c $(OBJC)
		$(CC) $(CFLAGS)  $(OBJC) -o client
$(SERVER) : server.c $(OBJS)
		$(CC) $(CFLAGS)  $(OBJS) -o server

bonus: $(CLIENT_BONUS) $(SERVER_BONUS)
$(CLIENT_BONUS) : client_bonus $(OBJCB)
		$(CC) $(CFLAGS)  $(OBJCB) -o client_bonus
$(SERVER_BONUS) : server_bonus.c $(OBJSB)
		$(CC) $(CFLAGS)  $(OBJSB) -o server_bonus
clean:
	rm -rf utilities.o client.o server.o  server_bonus.o  client_bonus.o 
fclean: clean
	rm -rf $(CLIENT) $(SERVER) $(CLIENT_BONUS) $(SERVER_BONUS)

re: fclean all bonus