NAME        = so_long
INCLUDES    = include/
SRC_DIR     = src/
OBJ_DIR     = build/
CC          = gcc
CFLAGS      = -Wall -Wextra -Werror -g
PRFLAGS     = -ldl -lglfw -pthread -lm
RM          = rm -rf

LIBFT_DIR   = libft/
LIBFT       = $(LIBFT_DIR)libft.a
LIBFT_CFLAGS = -fPIC

MLX_DIR     = MLX42/
MLX         = $(MLX_DIR)build/libmlx42.a
MLX_BUILD   = $(MLX_DIR)build
MLX_STAMP   = $(MLX_BUILD)/.stamp

SRC_FILES   = main.c maps.c mouv_perso.c mouv_barrel.c map_valid.c exit.c

SRC         = $(addprefix $(SRC_DIR), $(SRC_FILES))
OBJ         = $(SRC:$(SRC_DIR)%.c=$(OBJ_DIR)%.o)

OBJ_CACHE   = .cache_exists

VERBOSE     ?= 0

ifeq ($(VERBOSE),1)
    MAKEFLAGS += --debug=b
    Q :=
else
    Q := @
endif

all: $(MLX) $(LIBFT) $(NAME)
	@echo "\033[0;32mso_long is up to date.\033[0m"

$(LIBFT):
	$(Q)make -C $(LIBFT_DIR) CFLAGS+=$(LIBFT_CFLAGS)

$(MLX): $(MLX_STAMP)

$(MLX_STAMP): | $(MLX_BUILD)
	$(Q)if [ ! -f $(MLX) ] || [ ! -f $@ ] || [ $(MLX) -nt $@ ]; then \
		echo "\033[0;33mCompiling MLX42...\033[0m"; \
		cmake $(MLX_DIR) -B $(MLX_BUILD) && \
		make -C $(MLX_BUILD) -j4 && \
		touch $@; \
	else \
		echo "\033[0;32mMLX42 is up to date.\033[0m"; \
	fi

$(MLX_BUILD):
	$(Q)mkdir -p $@

$(NAME): $(OBJ)
	$(Q)$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(MLX) $(PRFLAGS) -o $(NAME)
	@echo "\033[0;32m$(shell echo $(NAME) | tr '[:lower:]' '[:upper:]') : COMPILED\033[0m"

$(OBJ_DIR)%.o: $(SRC_DIR)%.c | $(OBJ_CACHE)
	@echo "\033[0;33mCompiling $<\033[0m"
	$(Q)$(CC) $(CFLAGS) -I$(INCLUDES) -I$(MLX_DIR)include -c $< -o $@

$(OBJ_CACHE):
	$(Q)mkdir -p $(OBJ_DIR)

clean:
	$(Q)make clean -C $(LIBFT_DIR)
	$(Q)$(RM) $(OBJ_DIR)
	$(Q)$(RM) $(OBJ_CACHE)
	@echo "\033[0;34mso_long and libs object files cleaned!\033[0m"

mlx_clean:
	$(Q)$(RM) -r $(MLX_BUILD)
	$(Q)$(RM) $(MLX_STAMP)
	@echo "\033[0;34mMLX42 build files cleaned!\033[0m"

fclean: clean mlx_clean
	$(Q)make fclean -C $(LIBFT_DIR)
	$(Q)$(RM) $(NAME)
	@echo "\033[0;34mso_long and libs executable files cleaned!\033[0m"

re: fclean all
	@echo "\033[0;32mCleaned and rebuilt everything for so_long!\033[0m"

.PHONY: all clean fclean re mlx_clean