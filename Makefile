NAME = so_long

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC_PATH = srcs
SRC		= main.c \
			hook/hook_func.c \
			hook/hook_utils.c \
			map/map.c \
			map/validate_map.c \
			map/is_map_solvable.c \
			map/visited_utils.c \
			map/draw_map.c \
			map/validate_map_utils.c \
			game/game.c \
			game/game_setup.c \
			game/game_setup_utils.c


OBJ_PATH	= obj
OBJ 		= $(SRC:.c=.o)
OBJS		= $(addprefix $(OBJ_PATH)/, $(OBJ))

INC_PATH = includes
INCS = -I$(INC_PATH) -I$(HOME)/minilibx-linux
MLX_PATH = $(HOME)/minilibx-linux
MLX = $(MLX_PATH)/libmlx_Linux.a

LIB_PATH	= libft
LIB			= libft.a
LIBS		= $(addprefix $(LIB_PATH)/, $(LIB))

RM			= rm -f

all: $(NAME)

# $(NAME): $(OBJS) $(MLX) $(LIBS)
# 	$(CC) $(CFLAGS) $(INCS) $(OBJS) $(MLX) $(LIBS) -framework OpenGL -framework AppKit -o $(NAME)
$(NAME): $(OBJS) $(MLX)
	make -C $(LIB_PATH)
	$(CC) $(CFLAGS) $(INCS) $(OBJS) $(MLX) $(LIBS) -L$(HOME)/minilibx-linux -lmlx -lXext -lX11 -o $(NAME)
# $(CC) $(CFLAGS) $(OBJS) $(MLX) -Lmlx -lmlx -L/usr/lib -Imlx -lXext -lX11 -lm -lz -o $(NAME)
# $(CC) $(CFLAGS) $(OBJS) $(MLX) -framework OpenGL -framework AppKit -o $(NAME)


$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(INCS) -c $< -o $@

$(MLX):
	$(MAKE) -C $(MLX_PATH)

# $(LIBS):
# 	$(MAKE) -C $(LIB_PATH)

clean:
	$(RM) $(OBJS)
	$(MAKE) -C $(MLX_PATH) clean
	$(MAKE) -C $(LIB_PATH) clean

fclean: clean
	$(RM) $(NAME)
	$(RM) -r $(OBJ_PATH)
	$(MAKE) -C $(MLX_PATH) clean
# 	$(MAKE) -C $(LIB_PATH) fclean

re: fclean all

.PHONY: all clean fclean re
