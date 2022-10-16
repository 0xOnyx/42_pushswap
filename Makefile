# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jerdos-s <marvin@42lausanne.ch>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/14 22:46:01 by jerdos-s          #+#    #+#              #
#    Updated: 2022/10/14 22:46:02 by jerdos-s         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRC_PATH = src/
SRC_OBJ = objs/
SRC_INCLUDES = includes/

HEADER = push_swap.h
SRC = main.c utils.c arg.c resolve.c swap.c push.c rotate.c reverse.c minmax.c list.c print_array.c list.c

CFLAGS = -Wall -Wextra -Werror -g3 -fsanitize=address
OPTIONS =  -I$(SRC_INCLUDES)

SRCS = $(addprefix $(SRC_PATH),$(SRC))
OBJ = $(SRC:.c=.o)
OBJS = $(addprefix $(SRC_OBJ),$(OBJ))
HEADERS = $(addprefix $(SRC_INCLUDES),$(HEADER))

CC = gcc
RM = rm -f

$(SRC_OBJ)%.o: $(SRC_PATH)%.c $(HEADERS)
	mkdir -p $(SRC_OBJ)
	$(CC) $(CFLAGS) $(OPTIONS) -o $(@) -c $(<)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OPTIONS) -o $(@) $(^)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all fclean clean re
