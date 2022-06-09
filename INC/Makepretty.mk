
# COLORS
RED		= \x1b[31m
PINK	= \x1b[35m
BLUE	= \x1b[34m
LOVE	= \x1b[36m
RESET	= \x1b[0m
GREEN	= \x1b[32m
YELLOW	= \x1b[33m
NC		= \033[0m # No Color

# COMMANDS
RM = rm -rf
MAKE_C = make -C
NEW_DIR = mkdir -p

START_MESSAGE	= @echo "$(BLUE)---\nStarting...!\n---$(NC)"
REM_MESSAGE		= @echo "$(RED)Removing files...$(NC)"
RUN_MESSAGE		= @echo "$(BLUE)---\nCompiling done! Run ./$(NAME)\n---$(NC)"
COMP_MESSAGE	= "$(GREEN)Building C object... $(NC)%-33.33s\r\n"

PROJECT_MESSAGE = @echo "$(YELLOW)~~~~~~~~~ Done, you can now use this Super-$(NAME) o/"
COMPILE_MESSAGE	= @echo "$(PINK)Compiling$(RESET) $< $@"
MESSAGE_LINKED	= @echo "$(GREEN)Compiling$(RESET) $< $@"
MESSAGE_PRINTF	= @echo "$(BLUE)Compiling$(RESET) $< $@"

EMPTY_MESSAGE	= @echo ""
MESSY_MESSAGE	= @echo "$(GREEN)$@ $(PINK)$(NAME)"
DONE_MESSAGE 	= @echo "$(YELLOW)	done.\n"

RESET_MESSAGE_3	= @echo "	   $(RESET)Done"
RESET_MESSAGE_2	= @echo "	$(PINK)RE$(GREEN)COM$(YELLOW)PI$(BLUE)LIN$(LOVE)G"
RESET_MESSAGE_1	= @echo "	$(RESET)   $(NAME)\n"

ADD_GIT_IGNORE	= @echo $@ "\n"obj "\n".gitignore >> .gitignore
BYE_GIT_IGNORE	= @$(RM) .gitignore
