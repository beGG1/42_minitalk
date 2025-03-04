NAME = server client server_bonus client_bonus
NAME_S = server
NAME_C = client
NAME_SB = server_bonus
NAME_CB = client_bonus

CC = cc

CFLAGS = -Wall -Werror -Wextra -g 
LIBFT = ./includes/libft/libft.a

SRC = 	srcs/server.c

SRC_S = srcs/server.c	\
		srcs/int_converter.c
SRC_C = srcs/client.c	\
		srcs/int_converter.c

all: $(NAME_S) $(NAME_C)

$(NAME_S): $(SRC:.c=.o)
	$(MAKE) --no-print-directory -C ./includes/libft
	echo "LIBFT done"
	$(CC) $(CFLAGS) -lm $(SRC_S) $(LIBFT) -o $(NAME_S)
	echo "Server is ready"

$(NAME_C): $(SRC:.c=.o)
	$(MAKE) --no-print-directory -C ./includes/libft
	echo "LIBFT done"
	$(CC) $(CFLAGS) -lm $(SRC_C) $(LIBFT) -o $(NAME_C)
	echo "Client is ready"

clean:
	$(MAKE) clean -C ./includes/libft
	rm -rf $(SRC:.c=.o)
	echo "OBJ deleted"

fclean: clean
	$(MAKE) fclean -C ./includes/libft
	rm -rf $(NAME)
	echo "$(NAME) deleted"

re: fclean all

.PHONY: all, clean, fclean, re, bonus

.SILENT: