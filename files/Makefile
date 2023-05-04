NAME	=	philo

CC		=	cc
CFLAGS	=	-Wall -Werror -Wextra -pthread -fsanitize=thread

SRC		=	philo.c ./utils/philo_utils.c ./utils/general_utils.c

RED		=	\033[91;1m
GREEN	=	\033[92;1m
YELLOW	=	\033[93;1m
BLUE	=	\033[94;1m
PINK	=	\033[95;1m
CLEAR	=	\033[0m

all:		$(NAME)

$(NAME):
			@echo "$(BLUE)Make all$(CLEAR)\n$(PINK)Compiling.$(CLEAR)"
			@$(CC) $(CFLAGS) -o $(NAME) $(SRC)
			@echo "$(GREEN)Success!$(CLEAR)\n$(YELLOW)Finished$(CLEAR)\n"

clean:
			@echo "$(BLUE)Make clean/fclean$(CLEAR)\n$(RED)Removing all compiled files.$(CLEAR)"
			@rm -f $(NAME)
			@echo "$(GREEN)Success!$(CLEAR)\n$(YELLOW)Finished$(CLEAR)\n"

fclean:		clean

re:			fclean all