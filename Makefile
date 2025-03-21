NAME = server client server_bonus client_bonus
NAME_S = server
NAME_C = client
NAME_SB = server_bonus
NAME_CB = client_bonus

CC = cc

CFLAGS = -Wall -Werror -Wextra -g 
LIBFT = ./includes/libft/libft.a

SRC = 	srcs/server.c \
		srcs/client.c

SRC_B = srcs/server_bonus.c \
		srcs/client_bonus.c

SRC_S = srcs/server.c
SRC_C = srcs/client.c

SRC_SB = srcs/server_bonus.c
SRC_CB = srcs/client_bonus.c

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

$(NAME_SB): $(SRC_B:.c=.o)
	$(MAKE) --no-print-directory -C ./includes/libft
	echo "LIBFT done"
	$(CC) $(CFLAGS) -lm $(SRC_SB) $(LIBFT) -o $(NAME_SB)
	echo "Server bonus is ready"

$(NAME_CB): $(SRC_B:.c=.o)
	$(MAKE) --no-print-directory -C ./includes/libft
	echo "LIBFT done"
	$(CC) $(CFLAGS) -lm $(SRC_CB) $(LIBFT) -o $(NAME_CB)
	echo "Client bonus is ready"

bonus: server_bonus client_bonus

clean:
	$(MAKE) clean -C ./includes/libft
	rm -rf $(SRC:.c=.o)
	rm -rf $(SRC_B:.c=.o)
	echo "OBJ deleted"

fclean: clean
	$(MAKE) fclean -C ./includes/libft
	rm -rf $(NAME)
	echo "$(NAME) deleted"

re: fclean all

.PHONY: all, clean, fclean, re, bonus

.SILENT: