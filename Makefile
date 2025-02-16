CC = cc
CFLAGS = -Wall -Wextra -Werror

LIBFTDIR = ./libft
PRINTFDIR = ./ft_printf

CLIENT_SRC = client.c convertion.c
SERVER_SRC = server.c

CLIENT_OBJS = $(CLIENT_SRC:.c=.o)
SERVER_OBJS = $(SERVER_SRC:.c=.o)

CLIENT = client
SERVER = server

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

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	make clean -C $(LIBFTDIR)
	make clean -C $(PRINTFDIR)
	$(DELETE) $(CLIENT_OBJS) $(SERVER_OBJS)

fclean: clean
	make fclean -C $(LIBFTDIR)
	make fclean -C $(PRINTFDIR)
	$(DELETE) $(CLIENT) $(SERVER)

re: fclean all

.PHONY: all clean fclean re

.SECONDARY: $(SERVER_OBJS) $(CLIENT_OBJS)
