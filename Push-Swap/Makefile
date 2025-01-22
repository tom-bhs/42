NAME = push_swap

LIBFT = ./inc/libft/libft.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRCS 	= 	src/main.c \
		src/push_swap.c \
		src/operations.c \
		src/ft_error.c    \
		src/utils.c        \
		src/utils_2.c	    \

OBJS = $(SRCS:.c=.o)
LIBFT_DIR = ./inc/libft

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -L$(LIBFT_DIR) -lft

$(LIBFT):
	make -C $(LIBFT_DIR)

clean:
	make -C $(LIBFT_DIR) clean
	rm -f $(OBJS)

fclean: clean
	make -C $(LIBFT_DIR) fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
