# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rvarela- <rvarela-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/03 11:30:21 by rvarela-          #+#    #+#              #
#    Updated: 2024/02/03 11:34:08 by rvarela-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap.a

FLAGS = -Wall -Werror -Wextra

SRC = main.c #add functions

OBJ = $(SRC:.c=.o)

#Create push_swap.a
all: $(NAME)

%.o: %.c
cc $(FLAGS) -c $< -I. -o $@