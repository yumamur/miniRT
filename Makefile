NAME	=	miniRT

CC		=	clang
CFLAGS	=	-Wall -Werror -Wextra

DEFINES		=
INCLUDES	=

LIB_MAC = -framework AppKit -framework OpenGL -L./minilibx/ -lmlx
LIB_LNX = -L./minilibx -lmlx -lXext -lX11 -lm

LIBFT	=	src/libft/libft.a
LIBMLX		=	minilibx/libmlx.a

SRC		=	$(wildcard src/*.c) \
			$(wildcard src/objects/*.c) \
			$(wildcard src/parsing/*.c) \
			$(wildcard src/util/*.c) \
			$(wildcard src/vector/*.c) \
			$(wildcard src/mlx_utils/*.c) \
			$(wildcard src/render/*.c)

# $(wildcard src/rendering/*.c)

.PHONY: all clean fclean re bonus debug

all: $(NAME)

clean:
	@$(MAKE) -sC src/libft clean
	@$(MAKE) -sC minilibx clean

fclean: clean
	@$(MAKE) -sC src/libft fclean
	@$(MAKE) -sC minilibx clean
	@rm -f $(NAME)

re: fclean all

bonus:

debug: CFLAGS += -g
debug: $(NAME)

define download_minilibx_mac
	@echo "Downloading minilibx..."
	@wget -q "https://cdn.intra.42.fr/document/document/18334/minilibx_opengl.tgz"
	@tar -xf minilibx_opengl.tgz
	@rm -f minilibx_opengl.tgz
	@mv minilibx_opengl minilibx
endef

define download_minilibx_linux
	@echo "Downloading minilibx..."
	@wget -q "https://cdn.intra.42.fr/document/document/18333/minilibx-linux.tgz"
	@tar -xf minilibx-linux.tgz
	@rm -f minilibx-linux.tgz
	@mv minilibx-linux minilibx
endef

$(NAME): $(LIBFT) $(LIBMLX) $(SRC)
	@$(CC) $(CFLAGS) $(DEFINES) $(INCLUDES) -o $(NAME) $(SRC) $(LIBFT) $(LIB_LNX)

$(LIBMLX):
	@$(call download_minilibx_linux)
	@$(MAKE) -sC minilibx

$(LIBFT):
	@$(MAKE) -sC src/libft
