NAME = so_long

CC = cc
CFLAGS = -Wall -Wextra -Werror


SRC_PATH = srcs
SRC		= main.c \

OBJ_PATH	= obj
OBJ 		= $(SRC:.c=.o)
OBJS		= $(addprefix $(OBJ_PATH)/, $(OBJ))

# INC_PATH = includes
# INCS		= -I$(INC_PATH)

MLX_PATH = mlx
MLX = $(MLX_PATH)/libmlx.a

# LIB_PATH	= libft
# LIB			= libft.a
# LIBS		= $(addprefix $(LIB_PATH)/, $(LIB))

RM			= rm -f

all: $(NAME)

# $(NAME): $(OBJS) $(MLX) $(LIBS)
# 	$(CC) $(CFLAGS) $(INCS) $(OBJS) $(MLX) $(LIBS) -framework OpenGL -framework AppKit -o $(NAME)
$(NAME): $(OBJS) $(MLX)
	$(CC) $(CFLAGS) $(OBJS) $(MLX) -Lmlx -lmlx -lX11 -o $(NAME)
# $(CC) $(CFLAGS) $(OBJS) $(MLX) -Lmlx -lmlx -L/usr/lib -Imlx -lXext -lX11 -lm -lz -o $(NAME)
# $(CC) $(CFLAGS) $(OBJS) $(MLX) -framework OpenGL -framework AppKit -o $(NAME)


$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
	mkdir -p $(OBJ_PATH)
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
	$(MAKE) -C $(MLX_PATH) clean
	$(MAKE) -C $(LIB_PATH) fclean

re: fclean all

.PHONY: all clean fclean re
