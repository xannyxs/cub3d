# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: xvoorvaa <xvoorvaa@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2022/02/01 14:31:21 by xvoorvaa      #+#    #+#                  #
#    Updated: 2022/07/28 16:00:59 by swofferh      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

include INC/Makepretty.mk

NAME			=	cub3d
CFLAGS			=	-Wall -Wextra -Werror
OBJ_DIR			=	OBJ
SRC_DIR			=	SRC
INC_DIR			=	INC
MLX_DIR			=	./LIB/MLX42
MLX_H			=	$(MLX_DIR)/include/
MLX_A			=	$(MLX_DIR)/libmlx42.a
LIBFT_DIR		=	./LIB/LIBSU
LIBFT_H			=	$(LIBFT_DIR)/inc
LIBFT_A			=	$(LIBFT_DIR)/libft.a
SOURCES			=  	SRC/parsing/check_map.c\
					SRC/parsing/check_unknown.c\
					SRC/parsing/check_wall_utils.c\
					SRC/parsing/is_wall_enclosed.c\
					SRC/parsing/check_player.c\
					SRC/parsing/check_wall.c\
					SRC/parsing/get_data.c\
					SRC/parsing/process_colours.c\
\
					SRC/raycasting/my_mlx_get_colour.c\
					SRC/raycasting/my_mlx_resize_window.c\
					SRC/raycasting/raycasting_utils.c\
					SRC/raycasting/movement.c\
					SRC/raycasting/my_mlx_put_pixel.c\
					SRC/raycasting/raycasting.c\
					SRC/raycasting/set_delta_dist.c\
					SRC/raycasting/draw.c\
\
					SRC/starting/cub3d.c\
					SRC/starting/file_validation.c\
					SRC/starting/init_sys.c\
					SRC/starting/read_file.c\
\
					SRC/utils/error_msg.c\
					SRC/utils/find_player.c\
					SRC/utils/get_next_line.c\
					SRC/utils/is_monitor_valid.c\
					SRC/utils/linked_list.c
HEADERS			:= $(MLX_H) INC/cub3d.h INC/error.h INC/raycast.h $(LIBFT_H)
OBJS			:= $(SOURCES:.c=.o)
OBJECTS			:= $(patsubst $(SRC_DIR)/%,$(OBJ_DIR)/%,$(OBJS))
GLFW_LIB 		:= $(shell brew --prefix glfw)

# define it with DEBUG=1
ifdef DEBUG
	CFLAGS += -g3 -fsanitize=address -Ofast
else
	CFLAGS += -Ofast
endif

all: $(NAME)

$(NAME): $(START) $(MLX_A) $(LIBFT_A) $(OBJECTS)
	@$(CC) $(CFLAGS) \
	$(MLX_A) -lglfw \
	-L $(GLFW_LIB)/lib $(LIBFT_A) \
	$(OBJECTS) -o $(NAME)
	@echo $(RUN_MESSAGE)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(HEADERS) | $(OBJ_DIR)
	@$(NEW_DIR) $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@ -I$(INC_DIR) -I$(MLX_H) -I$(LIBFT_H)
	@echo $(COMPILE_MESSAGE)
	
# ---------- CUB3D
$(OBJ_DIR):
	@echo $(START_CUB3D)
	@$(NEW_DIR) $@

# ---------- LIBFT
$(LIBFT_A): $(LIBFT_H)
	@echo $(START_LIBFT)
	@$(MAKE_C) $(LIBFT_DIR)

# ---------- MLX42
$(MLX_A): $(MLX_H)
	@echo $(START_MLX42)
	@$(MAKE_C) $(MLX_DIR)

clean:
	@$(RM) $(OBJ_DIR)
	@echo $(REM_MESSAGE)
	@echo $(RESET_MESSAGE)

fclean:	clean
	@$(RM) $(NAME)
	@$(RM) $(NAME).dSYM
	@$(RM) $(MLX_A)
	@$(MAKE_CLEAN) $(LIBFT_DIR)
	@$(MAKE_CLEAN) $(MLX_DIR)
	@echo $(RESET_MESSAGE)

re:	fclean all

norm:
	norminette INC
	norminette SRC
	norminette LIB/LIBSU

run: all
	./$(NAME) MAP/test.cub

cub: all
	./$(NAME) MAP/subject.cub

42: all
	./$(NAME) MAP/42.cub

museum: all 
	./$(NAME) MAP/VanGogh.cub


.PHONY:	all clean fclean re
