NAME = push_swap
CC = gcc
CFLAGS = -Wall -Wextra -Werror 


SRCS	=	src/main.c   \
			src/mouv.c    \
			src/sort.c     \
			src/error.c     \
			src/utils.c      \
			src/stack.c       \
			src/sort_utils.c   \
			src/stack_utils.c   \
			src/commandes/push.c \
			src/commandes/swap.c  \
			src/commandes/rotate.c \
			src/commandes/reverse.c \

OBJS = $(SRCS:.c=.o)


all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re