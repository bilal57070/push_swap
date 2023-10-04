

SRCS = main.c parsing.c parsing2.c mouv.c utils.c sort.c utils2.c \
		smallsort.c \

OBJS = ${SRCS:.c=.o}
NAME = push_swap
CC = gcc
FLAGS = -Wall -Wextra -Werror -Wno-error
RM = rm -rf
LIBFT = ./libft

all : ${NAME}

${NAME}: ${OBJS}
		 ${MAKE} -C ${LIBFT}/	
		 ${CC} ${FLAGS} ${OBJS} ${LIBFT}/libft.a -o $(NAME)

.c.o:
		${CC} ${FLAGS} -c $< -o ${<:.c=.o}

clean: 
		${MAKE} clean -C ${LIBFT}/
		${RM} ${OBJS}

fclean: clean
		${RM} ${NAME} ${LIBFT}/libft.a

re: fclean all

.PHONY: all clean flcean re