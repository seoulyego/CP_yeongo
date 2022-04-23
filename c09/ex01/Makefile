# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yeongo <yeongo@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/23 09:23:48 by yeongo            #+#    #+#              #
#    Updated: 2022/04/23 09:31:53 by yeongo           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror -c

AR = ar
ARFLAGS = rcus

NAME = libft.a

SRC_DIR = srcs
INC_DIR = includes

SRCS = $(SRC_DIR)/ft_putchar.c	\
	   $(SRC_DIR)/ft_swap.c	\
	   $(SRC_DIR)/ft_putstr.c	\
	   $(SRC_DIR)/ft_strlen.c	\
	   $(SRC_DIR)/ft_strcmp.c
OBJS = $(SRCS:.c=.o)

%.o : %.c
	$(CC) $(CFLAGS) -o $@ $< -I $(INC_DIR)

$(NAME) : $(OBJS)
	$(AR) $(ARFLAGS) $@ $^

.PHONY : all clean fclean re

all : $(NAME)

clean :
	rm -rf $(OBJS)

fclean : clean
	rm -rf $(NAME)

re : fclean all
