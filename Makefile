# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eboulajd <eboulajd@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/01 11:41:32 by eboulajd          #+#    #+#              #
#    Updated: 2026/01/30 17:20:21 by eboulajd         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Compiler and flags
CC = cc
CFLAGS = -Wall -Wextra -Werror

# Executable
NAME = push_swap

# Header files
HEADER = push_swap.h

# Source files
SRC = push_stack.c \
      reverse_rotate_stack.c \
	  rreverse_rotate_stack.c \
      rotate_stack.c \
      rrotate_stack.c \
      sswap_stack.c \
      stack_utils.c \
      swap_stack.c \
      args_to_int_array.c \
      check_duplicate.c \
      ft_split_args.c \
      ft_strjoin.c \
      is_valid_args.c \
      push_array_in_to_stack.c \
      main.c \
      indexing.c \
      chunk_sort.c \
	  sort.c

# Object files
OBJ = $(SRC:.c=.o)

# Rules
all: $(NAME)

# Compile executable
$(NAME): $(OBJ)
	$(CC)  -o $(NAME) $(OBJ)

# Compile .c -> .o
%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

# Remove object files
clean:
	rm -f $(OBJ)

# Remove object files + executable
fclean: clean
	rm -f $(NAME)

# Rebuild everything
re: fclean all

.PHONY: all clean fclean re