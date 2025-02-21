CC = cc
CFLAGS = -Wall -Wextra -Werror

LIBFTDIR = ./libft
PRINTFDIR = ./ft_printf

CLIENT_SRC = client.c
SERVER_SRC = server.c

CLIENT_BSRC = client_bouns.c
SERVER_BSRC = server_bouns.c

CLIENT_OBJS = $(CLIENT_SRC:.c=.o)
SERVER_OBJS = $(SERVER_SRC:.c=.o)

CLIENT_BOBJS = $(CLIENT_BSRC:.c=.o)
SERVER_BOBJS = $(SERVER_BSRC:.c=.o)

CLIENT = client
SERVER = server

CLIENT_BNS = client_bonus
SERVER_BNS = server_bonus

DELETE = rm -f

all: $(CLIENT) $(SERVER)

$(CLIENT): $(CLIENT_OBJS)
	make -C $(LIBFTDIR)
	make -C $(PRINTFDIR)
	$(CC) $(CFLAGS) $(CLIENT_OBJS) $(LIBFTDIR)/libft.a $(PRINTFDIR)/printf.a -o $(CLIENT)

$(SERVER): $(SERVER_OBJS)
	make -C $(LIBFTDIR)
	make -C $(PRINTFDIR)
	$(CC) $(CFLAGS) $(SERVER_OBJS) $(LIBFTDIR)/libft.a $(PRINTFDIR)/printf.a -o $(SERVER)

bonus: $(CLIENT_BNS) $(SERVER_BNS)

$(CLIENT_BNS): $(CLIENT_BOBJS)
	make -C $(LIBFTDIR)
	make -C $(PRINTFDIR)
	$(CC) $(CFLAGS) $(CLIENT_BOBJS) $(LIBFTDIR)/libft.a $(PRINTFDIR)/printf.a -o $(CLIENT_BNS)

$(SERVER_BNS): $(SERVER_BOBJS)
	make -C $(LIBFTDIR)
	make -C $(PRINTFDIR)
	$(CC) $(CFLAGS) $(SERVER_BOBJS) $(LIBFTDIR)/libft.a $(PRINTFDIR)/printf.a -o $(SERVER_BNS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	make clean -C $(LIBFTDIR)
	make clean -C $(PRINTFDIR)
	$(DELETE) $(CLIENT_OBJS) $(SERVER_OBJS) $(CLIENT_BOBJS) $(SERVER_BOBJS)

fclean: clean
	make fclean -C $(LIBFTDIR)
	make fclean -C $(PRINTFDIR)
	$(DELETE) $(CLIENT) $(SERVER) $(CLIENT_BNS) $(SERVER_BNS)

re: fclean all

.PHONY: all clean fclean re

# .SECONDARY: $(SERVER_OBJS) $(CLIENT_OBJS)
