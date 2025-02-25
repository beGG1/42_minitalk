NAME = server

CC = cc

CFLAGS = -Wall -Werror -Wextra -g 
LIBFT = ./includes/libft/libft.a

SRC = 	srcs/server.c

all: $(NAME)

$(NAME): $(SRC:.c=.o)
	$(MAKE) --no-print-directory -C ./includes/libft
	echo "LIBFT done"
	$(CC) $(CFLAGS) -lm $(SRC) $(LIBFT) -o $(NAME)
	echo "Server is ready"

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