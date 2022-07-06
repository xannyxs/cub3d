# MAKE IT PRETTY
-- 	= ---------
--- = $(--)$(--)--
N	= \n

# COLORS
RESET	= \x1b[0m
RED		= \x1b[31;1m
BLACK	= \033[30;1m
MAGENTA	= \033[35;1m
YELLOW	= \x1b[33;1m
PINK	= \x1b[35;1m
BLUE	= \x1b[34;1m
GREEN	= \x1b[32;1m
BOLD	= \033[1m
NC		= \033[0m# No Color

# COMMANDS
CC 				= gcc
RM 				= rm -rf
MAKE_C 			= make -C
MAKE_CLEAN 		= make fclean -C
NEW_DIR 		= mkdir -p

START_MLX42		= @echo "$(N)$(MESSY_MESSAGE)$(GREEN)$(---)$(N)  Starting MLX42$(N)$(---)$(RESET)"
START_CUB3D		= @echo "$(N)$(PINK)$(---)-----$(N)    Starting CUB3D$(N)$(---)-----$(N)$(RESET)"$(MESSAGE_CUB3D)
START_LIBFT		= @echo "$(N)$(BLUE)$(---)--$(N)    Starting LIBFT$(N)$(---)--$(RESET)"
PROJECT_MESSAGE = @echo "$(YELLOW)You can now run ./$(NAME)$(N)$(NC)"

MESSAGE_CUB3D	= "$(PINK)Compiling$(RESET) >>>> CUB3D <<<<"
COMPILE_MESSAGE	= @echo "$(PINK)Compiling$(RESET) $<"
REM_MESSAGE		= @echo "$(RED)$(N)Cleaning $(NC)CUB3D"
RUN_MESSAGE		= @echo "$(PINK)$(--)$(N)Compiling Done!$(N)$(--)$(N)"

EMPTY_MESSAGE	= @echo ""
MESSY_MESSAGE	= . $(YELLOW)LET'S $(BLUE)MAKE $(PINK)CUB3D$(RESET) .$(N)$(N)
DONE_MESSAGE 	= @echo "$(YELLOW)	done.$(N)"

RESET_MESSAGE	= @echo "	 $(RESET)Done.\n"
RESET_MESSAGE_2	= @echo "	$(PINK)RE$(GREEN)COM$(YELLOW)PI$(BLUE)LIN$(LOVE)G"
RESET_MESSAGE_1	= @echo "	$(RESET)   $(NAME)$(N)"

ADD_GIT_IGNORE	= @echo $@ "$(N)"obj "$(N)".gitignore >> .gitignore
BYE_GIT_IGNORE	= @$(RM) .gitignore