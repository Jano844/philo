NAME				=	philo

COMPILE				=	cc

FLAGS				=	-Wall -Wextra -Werror -o3

# LEAKS_SANITIZER		=	-L/Users/jsanger/Documents/LeakSanitizer/ -llsan

# LINUXFLAGS			=	-pthread

COLOR_RESET			=	\033[0m
COLOR_CYAN			=	\033[36m
COLOR_GREEN			=	\033[32m
COLOR_RED			=	\033[31m


SRCS				=	src/philo.c src/threads.c src/error.c src/init.c src/init_data.c src/eating.c src/utils.c


OBJS				=	$(SRCS:.c=.o)

all: $(NAME)

$(NAME):			$(INCLUDE) $(OBJS)
					@$(COMPILE) $(FLAGS) -o $(NAME) $(OBJS) $(LINUXFLAGS) $(LEAKS_SANITIZER)
					@echo "$(COLOR_CYAN)Kompilierung abgeschlossen: $(NAME)$(COLOR_RESET)"

%.o: %.c
					@$(COMPILE) $(FLAGS) -c $< -o $@
					@echo "$(COLOR_GREEN)Kompilierung abgeschlossen: $@$(COLOR_RESET)"

clean:
					@echo "$(COLOR_RED)Cleanup philo.$(COLOR_RESET)"
					@rm -f $(OBJS)
					@echo "$(COLOR_GREEN)Cleanup completed.$(COLOR_RESET)"

fclean:				clean
					@echo "$(COLOR_RED)Start Full-Clean.$(COLOR_RESET)"
					@rm -f $(NAME)
					@echo "$(COLOR_GREEN)Full-Clean completed.$(COLOR_RESET)"

re:					fclean all

.PHONY:				all clean fclean re
