# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rvarela <rvarela@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/03 11:30:21 by rvarela-          #+#    #+#              #
#    Updated: 2024/03/17 11:27:07 by rvarela          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

FLAGS = -Wall -Werror -Wextra -g

SRCDIR = src

INCDIR = includes

SRC = main.c ft_split.c stack_init.c error_check.c push_op.c rev_rot_op.c \
	rotate_op.c sort_three.c stack_utils.c stack_utils2.c swap_op.c \
	turk_algo.c prepare_stack.c

OBJ = $(addprefix $(SRCDIR)/, $(SRC:.c=.o))

#Create push_swap
all: $(NAME)

$(NAME): $(OBJ)
	cc $(FLAGS) $(OBJ) -o $(NAME)

$(SRCDIR)/%.o: $(SRCDIR)/%.c
	cc $(FLAGS) -c $< -I $(INCDIR) -o $@

clean:
	rm -rf $(OBJ)
	
fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re