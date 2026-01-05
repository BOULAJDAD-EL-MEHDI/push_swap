# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eboulajd <eboulajd@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/01 11:41:32 by eboulajd          #+#    #+#              #
#    Updated: 2026/01/02 16:34:11 by eboulajd         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIB = push_swap.a

CC = cc

LIBH = push_swap.h

CFLAGS = -Wall -Wextra -Werror

LIBC = push_stack.c \
		reverse_rotate_stack.c \
		rotate_stack.c \
		rreverse_rotate_stack.c \
		rrotate_stack.c \
		sswap_stack.c \
		stack_utils.c \
		swap_stack.c

SRCS = ${LIBC}

OBJS = ${SRCS:.c=.o}

%.o: %.c ${LIBH}
	${CC} ${CFLAGS} -c $< -o $@

${LIB}: ${OBJS} ${LIBH}
	ar -rsc ${LIB} ${OBJS}

all: ${LIB}

clean:
	rm -f ${OBJS}

fclean: clean
	rm -f ${LIB}

re: fclean all

.PHONY: all clean fclean re



