# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: xvoorvaa <xvoorvaa@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2022/02/01 14:31:21 by xvoorvaa      #+#    #+#                  #
#    Updated: 2022/06/09 19:53:53 by swofferh      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

include INC/Makepretty.mk

NAME			=	cub3d
CC				=	gcc
CFLAGS			=	-Wall -Wextra -Werror
OBJ_DIR			=	OBJ
SRC_DIR			=	SRC
INC_DIR			=	INC
MLX_DIR			=	./MLX42
MLX_H			=	$(MLX_DIR)/include/
MLX_A			=	$(MLX_DIR)/libmlx42.a
LIBFT_DIR		=	./libft
LIBFT_H			=	$(LIBFT_DIR)/INC
LIBFT_A			=	$(LIBFT_DIR)/libft.a

SOURCES			=	$(shell find $(SRC_DIR) -type f -name "*.c")

HEADERS		:= $(MLX_H) INC_.h INC/error.h $(LIBFT_H)
OBJS		:= $(SOURCES:.c=.o)
OBJECTS		:= $(patsubst $(SRC_DIR)/%,$(OBJ_DIR)/%,$(OBJS))
GLFW_LIB 	:= $(shell brew --prefix glfw)

ifdef DEBUG
	CFLAGS += -g3 -fsanitize=address
else
	CFLAGS += -Ofast
endif

all:	$(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(HEADERS) | $(OBJ_DIR)
	@$(NEW_DIR) $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@ -I $(INC_DIR) -I $(MLX_H) -I $(LIBFT_H)

$(OBJ_DIR):
	@$(NEW_DIR) $@

$(NAME): $(MLX_A) $(LIBFT_A) $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o $(NAME) $(MLX_A) \
	-lglfw -L$(GLFW_LIB)/lib $(LIBFT_A)
	$(START_MESSAGE)
	@printf $(COMP_MESSAGE) $(SOURCES)
	$(RUN_MESSAGE)

$(LIBFT_A): $(LIBFT_H)
	$(MAKE_C)$(LIBFT_DIR)

$(MLX_A): $(MLX_H)
	$(MAKE_C) $(MLX_DIR)

clean:
	$(EMPTY_MESSAGE)
	@echo $(OBJECTS)
	@$(RM) $(OBJ_DIR)
	$(REM_MESSAGE)
	$(EMPTY_MESSAGE)


fclean:	clean
	@$(RM) $(NAME)
	@$(RM) $(NAME).dSYM
	@$(RM) $(MLX_A)
	$(MAKE_C) $(MLX_DIR) $@
	$(MAKE_C) $(LIBFT_DIR) $@

re:			fclean all

.PHONY:		all clean fclean re
