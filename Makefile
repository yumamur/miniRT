NAME	=	miniRT

CC		=	clang
CFLAGS	=	-Wall -Werror -Wextra -fenable-matrix -I./include

DEFINES		=
INCLUDES	=

LIB_MAC = -framework AppKit -framework OpenGL -L./minilibx/ -lmlx
LIB_LNX = -L./minilibx -lmlx -lXext -lX11 -lm

LIBFT	=	src/libft/libft.a
LIBMLX		=	minilibx/libmlx.a

SRC		=	src/main.c \
			src/vector/v3_vec.c \
			src/vector/v3_scal.c \
			src/util/errno.c \
			src/util/big_g.c \
			src/input/read_util.c \
			src/input/parse.c \
			src/input/validate.c \
			src/input/ft_atof.c

.PHONY: all clean fclean re bonus debug

all: $(NAME)

clean:

fclean: clean

re: fclean all

bonus:

debug: CFLAGS += -g

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

$(NAME): $(LIBFT) $(LIBMLX)
	@$(CC) $(CFLAGS) $(DEFINES) $(INCLUDES) -o $(NAME) $(SRC) $(LIBFT) $(LIB_LNX)

$(LIBMLX):
	@$(call download_minilibx_linux)
	@$(MAKE) -sC minilibx

$(LIBFT):
	@$(MAKE) bonus -sC src/libft
