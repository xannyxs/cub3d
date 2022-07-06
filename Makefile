# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: xvoorvaa <xvoorvaa@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2022/02/01 14:31:21 by xvoorvaa      #+#    #+#                  #
#    Updated: 2022/07/06 14:45:12 by swofferh      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

include INC/Makepretty.mk

ifdef DEBUG
	CFLAGS += -g3 -fsanitize=address
else
	CFLAGS += -Ofast
endif

NAME			=	cub3d
CFLAGS			=	-Wall -Wextra -Werror
OBJ_DIR			=	OBJ
SRC_DIR			=	SRC
INC_DIR			=	INC
MLX_DIR			=	./LIB/MLX42
MLX_H			=	$(MLX_DIR)/include/
MLX_A			=	$(MLX_DIR)/libmlx42.a
LIBFT_DIR		=	./LIB/LIBFT
LIBFT_H			=	$(LIBFT_DIR)/inc
LIBFT_A			=	$(LIBFT_DIR)/libft.a
SOURCES			=  $(shell find $(SRC_DIR) -type f -name "*.c")
HEADERS			:= $(MLX_H) INC/cub3d.h INC/error.h INC/raycast.h $(LIBFT_H)
OBJS			:= $(SOURCES:.c=.o)
OBJECTS			:= $(patsubst $(SRC_DIR)/%,$(OBJ_DIR)/%,$(OBJS))
GLFW_LIB 		:= $(shell brew --prefix glfw)

all: $(NAME)

$(NAME): $(START) $(MLX_A) $(LIBFT_A) $(OBJECTS)
	@$(CC) $(CFLAGS) $(OBJECTS) -o $(NAME) $(MLX_A) -lglfw \
		-L$(GLFW_LIB)/lib $(LIBFT_A)
	$(RUN_MESSAGE)
	$(PROJECT_MESSAGE)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(HEADERS) | $(OBJ_DIR)
	@$(NEW_DIR) $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@ -I$(INC_DIR) -I$(MLX_H) -I$(LIBFT_H)
	$(COMPILE_MESSAGE)
	
# ---------- CUB3D
$(OBJ_DIR):
	$(START_CUB3D)
	@$(NEW_DIR) $@

# ---------- LIBFT
$(LIBFT_A): $(LIBFT_H)
	$(START_LIBFT)
	@$(MAKE_C) $(LIBFT_DIR)

# ---------- MLX42
$(MLX_A): $(MLX_H)
	$(START_MLX42)
	@$(MAKE_C) $(MLX_DIR)

clean:
	@$(RM) $(OBJ_DIR)
	$(REM_MESSAGE)
	$(RESET_MESSAGE)

fclean:	clean
	@$(RM) $(NAME)
	@$(RM) $(NAME).dSYM
	@$(RM) $(MLX_A)
	@$(MAKE_CLEAN) $(LIBFT_DIR)
	@$(MAKE_CLEAN) $(MLX_DIR)
	$(RESET_MESSAGE)

re:	fclean all

run: all
	./$(NAME) MAP/subject.cub

cub: all
	./$(NAME) MAP/42.cub

.PHONY:	all clean fclean re
