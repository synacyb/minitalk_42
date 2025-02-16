# Compiler and Flags
CC = cc
CFLAGS = -Wall -Wextra -Werror

# Directories for libraries
LIBFTDIR = ./libft
PRINTFDIR = ./ft_printf

# Source files
CLIENT_SRC = client.c convertion.c
SERVER_SRC = server.c

# Object files
CLIENT_OBJS = $(CLIENT_SRC:.c=.o)
SERVER_OBJS = $(SERVER_SRC:.c=.o)

# Executable names
CLIENT = client
SERVER = server

# Cleanup variables
DELETE = rm -f

all: $(CLIENT) $(SERVER)

# Compile client
$(CLIENT): $(CLIENT_OBJS)
	make -C $(LIBFTDIR)
	make -C $(PRINTFDIR)
	$(CC) $(CFLAGS) $(CLIENT_OBJS) $(LIBFTDIR)/libft.a $(PRINTFDIR)/printf.a -o $(CLIENT)

# Compile server
$(SERVER): $(SERVER_OBJS)
	make -C $(LIBFTDIR)
	make -C $(PRINTFDIR)
	$(CC) $(CFLAGS) $(SERVER_OBJS) $(LIBFTDIR)/libft.a $(PRINTFDIR)/printf.a -o $(SERVER)

# Rule to create object files
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
