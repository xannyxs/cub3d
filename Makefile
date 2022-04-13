# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: xvoorvaa <xvoorvaa@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2022/02/01 14:31:21 by xvoorvaa      #+#    #+#                  #
#    Updated: 2022/04/13 21:53:08 by xvoorvaa      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME			=	cub3d
CC				=	gcc
CFLAGS			=	-Wall -Wextra -Werror
OBJ_DIR			=	OBJ
SRC_DIR			=	SRC
INC_DIR			=	INC
MLX_DIR			=	MLX42
MLX_H			=	$(wildcard $(MLX_DIR)/*.h)
MLX_A			=	$(MLX_DIR)/libmlx42.a

SRCS			=	$(SRC_DIR)/cub3d.c $(MLX_H)

OBJS			=	$(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
HEADERS			=	INC/cub3d.h $(MLX_DIR)/include/MLX42/MLX42.h

ifdef DEBUG
	CFLAGS += -g3 -fsanitize=address
else
	CFLAGS += -O2
endif

GREEN			=	\033[1;32m
BLUE			=	\033[1;36m
RED				=	\033[0;31m
NC				=	\033[0m # No Color

START			= "$(BLUE)---\nStarting...!\n---$(NC)"
MESSAGE			= "$(BLUE)---\nCompiling done! Run ./$(NAME)\n---$(NC)"
COMP_MESSAGE	= "$(GREEN)Building C object... $(NC)%-33.33s\r\n"
REM_MESSAGE		= "$(RED)Removing files...$(NC)"

all:	$(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(HEADERS) | $(OBJ_DIR)
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@ -I$(INC_DIR) -I$(MLX_DIR)

$(OBJ_DIR):
	mkdir $@

$(MLX_A): $(MLX_H)
	$(MAKE) -C $(MLX_DIR)

$(NAME): $(OBJS)
	@echo $(START)
	@printf $(COMP_MESSAGE) $(SRCS)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME) -L$(MLX_A) -lglfw
	@echo $(MESSAGE)

clean:
	@echo "\n"
	@rm -rf $(OBJ_DIR)
	@printf $(REM_MESSAGE)
	@echo "\n"


fclean:		clean
	@rm -f $(NAME)
	@rm -rf $(NAME).dSYM
	@rm -f $(MLX_A)

re:			fclean all

.PHONY:		all clean fclean re

