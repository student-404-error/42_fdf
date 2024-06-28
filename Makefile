# ANSI COLOR CODE
RED		:=	\033[31m
GREEN		:=	\033[32m
YELLOW		:=	\033[33m
BLUE		:=	\033[34m
MAGENTA		:=	\033[35m
CYAN		:=	\033[36m
WHITE		:=	\033[37m
RESET		:=	\033[0m

NAME		=	fdf

INCLUDES	=	./include

SRC_DIR		=	./src/fdf
SRCS		=	$(wildcard $(SRC_DIR)/*.c)

LIBFT		=	./src/libft/libft.a
LIBFT_DIR	=	./src/libft

CC			=	gcc
CFLAGS		=	-Wall -Werror -Wextra -g -I$(INCLUDES)

OBJS		=	$(SRCS:.c=.o)

%.o: %.c
	$(CC) -c $(CFLAGS) $< -o $@

#======================RULES=======================#

all		:	$(NAME)

$(NAME)		:	$(OBJS)
			@echo "$(GREEN)==========================$(RESET)"
			@echo "$(GREEN) Building $(MAGENTA)fdf$(GREEN)...$(RESET)"
			@make -C $(LIBFT_DIR)
			@$(CC) $(CFLAGS) -fPIE -pie $(OBJS) $(LIBFT) -o $(NAME)
			@echo "$(GREEN) Build complete!$(RESET)"
			@echo "$(GREEN)==========================$(RESET)"

clean		:
			@echo "$(RED)===========$(WHITE)clean$(RED)===========$(RESET)"
			@echo "$(RED)Cleaning up...$(RESET)"
			@rm -f $(OBJS)
			@cd $(LIBFT_DIR) && make clean
			@echo "$(RED)Cleaning complete!$(RESET)"
			@echo "$(RED)===========$(WHITE)clean$(RED)===========$(RESET)"

fclean		:	clean
			@echo "$(RED)===========$(CYAN)fclean$(RED)===========$(RESET)"
			@echo "$(RED)Deleting .a files...$(RESET)"
			@rm -f $(NAME)
			@cd $(LIBFT_DIR) && make fclean
			@echo "$(RED)Delete complete!$(RESET)"
			@echo "$(RED)===========$(CYAN)fclean$(RED)===========$(RESET)"

re		:	fclean	\
			all

.PHONY		:	all	\
			clean	\
			fclean	\
			re
