
# COLORS
RED		= \x1b[31;01m
PINK	= \x1b[35m
BLUE	= \x1b[34m
LOVE	= \x1b[36m
RESET	= \x1b[0m
GREEN	= \x1b[32;01m
YELLOW	= \x1b[33m

LIBFT_MESSAGE 	= @echo "$(YELLOW)~~~~~~~~~ Done, you can now use this Super-Libft.a o/"
COMPILE_MESSAGE	= @echo "$(BLUE)Compiling$(RESET) $<"
MESSAGE_LINKED	= @echo "$(YELLOW)Compiling$(RESET) $<"
MESSAGE_PRINTF	= @echo "$(GREEN)Compiling$(RESET) $<"
EXTRA_MESSAGE	= @echo "$(PINK)Compiling$(RESET) $<"

EMPTY_MESSAGE	= @echo ""
MESSY_MESSAGE	= @echo "$(RED)$@	$(RESET)LIBFT"
DONE_MESSAGE 	= @echo "$(RESET)	 Done.\n"
DONE_LIBFT		= @echo "$(N)$(BLUE)$(---)--$(N) Done compiling LIBFT$(N)$(---) --$(RESET)"

RESET_MESSAGE_3	= @echo "	   $(RESET)done"
RESET_MESSAGE_2	= @echo "	$(PINK)RE$(GREEN)COM$(YELLOW)PI$(BLUE)LIN$(LOVE)G"
RESET_MESSAGE_1	= @echo "	$(RESET)   $(PROJECT)\n"

ADD_GIT_IGNORE	= @echo $@ "\n"obj "\n".gitignore >> .gitignore
BYE_GIT_IGNORE	= @$(RM) .gitignore
