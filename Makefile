# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rvarela <rvarela@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/03 11:30:21 by rvarela-          #+#    #+#              #
#    Updated: 2024/02/04 16:45:23 by rvarela          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

FLAGS = -Wall -Werror -Wextra

SRCDIR = src

INCDIR = includes

SRC = main.c #add functions



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