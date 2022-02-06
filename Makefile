NAME = push_swap

CHECKER = checker

SRC = commands.c commands_2.c ft_atoi.c ft_calloc.c ft_memset.c ft_sort.c \
      ft_split.c ft_strdup.c ft_strlcpy.c ft_strlen.c ft_substr.c \
      push_swap.c stack_movs.c stack_movs_2.c stack_movs_3.c commands_3.c \
      sort_fuctions.c sort_tree.c sort_five.c sort_four.c sort_functions_2.c

CHECKER_SRC = ./checker_src/checker.c ./checker_src/get_next_line.c \
 			  ./checker_src/get_next_line_utils.c stack_movs.c stack_movs_2.c \
 			  stack_movs_3.c ft_atoi.c ft_calloc.c ft_memset.c \
             ft_split.c ft_strdup.c ft_strlcpy.c ft_strlen.c ft_substr.c \
             commands_2.c commands.c ./checker_src/ft_strcmp.c

OBJS = ${SRC:%.c=%.o}

CHECKER_OBJS = ${CHECKER_SRC:%.c=%.o}

CC = cc

FLAGS = -Wall -Wextra -Werror

MAKE = Makefile

HEAD = push_swap.h

RM = rm -rf

%.o:		%.c $(HEAD) $(MAKE)
	  		$(CC) $(FLAGS) -c $< -o ${<:.c=.o}

all:	$(NAME)

$(NAME):	$(OBJS)
			$(CC) $(FLAGS) -o $(NAME) $(OBJS)

$(CHECKER):	$(CHECKER_OBJS)
			$(CC) $(FLAGS) -o $(CHECKER) $(CHECKER_OBJS)


bonus:		$(CHECKER)

clean:
			$(RM) $(OBJS)

fclean: 	clean
			$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
