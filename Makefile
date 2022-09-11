SRCS		= shell_funcs.c before_five_elem.c operation_func.c start.c algorithm_third_step.c \
				check_errors_funcs.c utils_funcs.c counters_funcs.c steps_funcs.c

OBJS		= ${SRCS:.c=.o}

HDRS		= push_swap.h

GCC			= gcc -Wall -Wextra -Werror

NAME		= push_swap

LIBFT		= libft/

LIBFT.a		= ${LIBFT}libft.a

all:		${NAME}

%.o:		%.c ${HDRS} Makefile
			${GCC} -c -o $@ $<

$(NAME): 	${OBJS} Makefile
			cd ${LIBFT} && ${MAKE}
			${GCC} ${OBJS} ${LIBFT.a} -o ${NAME}

re:			fclean all

clean:
			rm -f ${OBJS}
			cd ${LIBFT} && ${MAKE} clean

fclean:		clean
			rm -f ${NAME}
			cd ${LIBFT} && ${MAKE} fclean

.PHONY:		all re clean fclean
