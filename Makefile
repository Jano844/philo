NAME				=	philo

COMPILE				=	cc -lpthread

# FLAGS				=	-Wall -Wextra -Werror

# THREADFLAG			= 

COLOR_RESET			=	\033[0m
COLOR_CYAN			=	\033[36m
COLOR_GREEN			=	\033[32m
COLOR_RED			=	\033[31m

INCLUDE				=	libft/

SRCS_FOLDER			=	srcs/

SRCS				=	src/philo.c src/thread_test.c


OBJS				=	$(SRCS:.c=.o)

all: $(NAME)

$(NAME):			$(INCLUDE) $(OBJS)
					@cd $(INCLUDE) && make
					@$(COMPILE) $(FLAGS) -o $(NAME) $(OBJS) -L$(INCLUDE) -lft $(LDFLAGS)
					@echo "$(COLOR_CYAN)Kompilierung abgeschlossen: $(NAME)$(COLOR_RESET)"

%.o: %.c
					@$(COMPILE) $(FLAGS) -c $< -o $@
					@echo "$(COLOR_GREEN)Kompilierung abgeschlossen: $@$(COLOR_RESET)"

clean:
					@echo "$(COLOR_RED)Cleanup MiniShell.$(COLOR_RESET)"
					@rm -f $(OBJS)
					@echo "$(COLOR_RED)Cleanup Libft.$(COLOR_RESET)"
					@cd $(INCLUDE) && make clean
					@echo "$(COLOR_GREEN)Cleanup completed.$(COLOR_RESET)"

fclean:				clean
					@echo "$(COLOR_RED)Start Full-Clean.$(COLOR_RESET)"
					@rm -f $(NAME)
					@echo "$(COLOR_RED)Full-Clean Libft.$(COLOR_RESET)"
					@cd $(INCLUDE) && make fclean
					@echo "$(COLOR_GREEN)Full-Clean completed.$(COLOR_RESET)"

re:					fclean all

.PHONY:				all clean fclean re
