# ANSI COLOR CODE
RED		:=	\033[31m
GREEN		:=	\033[32m
YELLOW		:=	\033[33m
BLUE		:=	\033[34m
MAGENTA		:=	\033[35m
CYAN		:=	\033[36m
RESET		:=	\033[0m

SRCS		=	$(wildcard ./*.c)
INCLUDES	=	../../include
CC		=	cc

CFLAGS		=	-Wall -Werror -Wextra -I$(INCLUDES)

OBJS		=	${SRCS:.c=.o}

NAME		=	libgnl.a

AR		=	ar

ARFLAGS		=	rsc

RM		=	rm -f

# ------------ RULE ------------ #

%.o: %.c
	@$(CC) -c $(CFLAGS) $< -o $@

all		:	$(NAME)

$(NAME)		:	$(OBJS)
			@$(AR) $(ARFLAGS) $(NAME) $(OBJS)

clean		:
			@$(RM) $(OBJS)
			
fclean		:	clean
			@$(RM) $(NAME)

re		:	fclean	\
			all

.PHONY		:	all	\
			fclean	\
			clean	\
			re
