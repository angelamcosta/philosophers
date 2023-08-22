NAME	=	philo

CC		=	cc
CFLAGS	=	-g -Wall -Werror -Wextra -pthread

SRC		=	philo.c \
			./src/ft_printf.c \
			./src/action_utils.c \
			./src/general_utils.c \
			./src/philo_utils.c \
			./src/verify_routine.c

OBJ		=	$(SRC:.c=.o)

RED		=	\033[91;1m
GREEN	=	\033[92;1m
YELLOW	=	\033[93;1m
BLUE	=	\033[94;1m
PINK	=	\033[95;1m
CLEAR	=	\033[0m

all:		$(NAME)

$(NAME):	$(OBJ)
			@echo "$(BLUE)Make all$(CLEAR)\n$(PINK)Compiling.$(CLEAR)"
			@norminette .
			@$(CC) $(CFLAGS) $(SRC) -o $(NAME)
			@echo "$(GREEN)Success!$(CLEAR)\n$(YELLOW)Finished$(CLEAR)\n"

clean:
			@echo "$(BLUE)Make clean$(CLEAR)\n$(RED)Removing all compiled files.$(CLEAR)"
			@rm -f $(OBJ)
			@echo "$(GREEN)Success!$(CLEAR)\n$(YELLOW)Finished$(CLEAR)\n"

fclean:		clean
			@rm -f $(NAME)

re:			fclean all

.PHONY:		all clean fclean re