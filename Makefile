NAME	=	miniRT

CC		=	clang
CFLAGS	=	-Wall -Werror -Wextra

DEFINES		=
INCLUDES	= -I./lib/libft -I./lib/minilibx

LIB_MAC = -framework AppKit -framework OpenGL -L./lib/minilibx/ -lmlx
LIB_LNX = -L./lib/minilibx -lmlx -lXext -lX11 -lm

LIBFT	=	lib/libft/libft.a
LIBMLX	=	lib/minilibx/libmlx.a

MAIN	=	src/main.c

SRC		=	$(wildcard src/objects/*.c) \
			$(wildcard src/parse/*.c) \
			$(wildcard src/util/*.c) \
			$(wildcard src/vector/*.c) \
			$(wildcard src/mlx_utils/*.c) \
			$(wildcard src/render/*.c)

# $(wildcard src/rendering/*.c)

.PHONY: all clean fclean re bonus debug

all: $(NAME)

clean:
	@$(MAKE) -sC lib/libft clean
	@$(MAKE) -sC lib/minilibx clean

fclean: clean
	@$(MAKE) -sC lib/libft fclean
	@$(MAKE) -sC lib/minilibx clean
	@rm -f $(NAME)

re: fclean all

bonus:

debug: CFLAGS += -g
debug: $(NAME)

asan: CFLAGS += -fsanitize=address
asan: $(NAME)

define download_minilibx_mac
	@echo "Downloading minilibx..."
	@wget -q "https://cdn.intra.42.fr/document/document/18334/minilibx_opengl.tgz"
	@tar -xf minilibx_opengl.tgz
	@rm -f minilibx_opengl.tgz
	@mv minilibx_opengl lib/minilibx
endef

define download_minilibx_linux
	@echo "Downloading minilibx..."
	@wget -q "https://cdn.intra.42.fr/document/document/18333/minilibx-linux.tgz"
	@tar -xf minilibx-linux.tgz
	@rm -f minilibx-linux.tgz
	@mv minilibx-linux lib/minilibx
endef

$(NAME): $(LIBFT) $(LIBMLX) $(MAIN) $(SRC)
	@$(CC) $(CFLAGS) $(DEFINES) $(INCLUDES) -o $(NAME) $(MAIN) $(SRC) $(LIBFT) $(LIB_LNX)

$(LIBMLX):
	@$(call download_minilibx_linux)
	@$(MAKE) -sC lib/minilibx

$(LIBFT):
	@$(MAKE) -sC lib/libft
