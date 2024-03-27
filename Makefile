NAME	=	miniRT

CC		=	clang
CFLAGS	=	-Wall -Werror -Wextra -fenable-matrix -I./include

DEFINES		=
INCLUDES	=

LIB_MAC = -framework AppKit -framework OpenGL -L./minilibx/ -lmlx
LIB_LNX = -lmlx -lXext -lX11

LIBFT	=	libft/libft.a
LIBMLX		=	minilibx/libmlx.a

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

$(NAME): $(LIBFT) $(LIBMLX)
	@$(CC) $(CFLAGS) $(DEFINES) $(INCLUDES) $(LIBFT) $(LIB_LNX) -o $(NAME) srcs/*.c

$(LIBMLX):
	@$(call download_minilibx_mac)
	@$(MAKE) -sC minilibx

$(LIBFT):
	@$(MAKE) -sC libft
