NAME = so_long
CC = cc
CFLAGS = -Wall -Wextra -Werror -g
LDFLAGS = -L$(MLX_DIR) -Llibs/ft_printf
LDLIBS =$(PRN_DIR)/libftprintf.a -lmlx -lX11 -lXext

PRN_DIR = libs/ft_printf
GNL_DIR = libs/get_next_line
MLX_DIR = minilibx-linux

SRCS = $(GNL_DIR)/get_next_line.c $(GNL_DIR)/get_next_line_utils.c move.c map_check.c \
	image_to_window.c map_malloc.c import_assets.c bonus/enemy_move.c so_long_utils.c \
	bonus/import_sprite.c bonus/enemy.c libs/ft_itoa.c libs/ft_strdup.c bonus/play_sprite.c main.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME):$(PRN_DIR)/libftprintf.a $(OBJS) $(MLX_DIR)/libmlx.a
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(LDFLAGS) $(LDLIBS)

$(PRN_DIR)/libftprintf.a:
	$(MAKE) -C $(PRN_DIR)

$(MLX_DIR)/libmlx.a:
	$(MAKE) -C $(MLX_DIR)

clean:
	rm -f $(OBJS)
	$(MAKE) -C $(PRN_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(PRN_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
