# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yeongo <yeongo@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/23 09:58:24 by yeongo            #+#    #+#              #
#    Updated: 2022/04/23 10:04:04 by yeongo           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror

NAME = ft_display_file

SRCS = string.c			\
	   error.c			\
	   init.c			\
	   display_file.c	\
	   main.c
OBJS = $(SRCS:.c=.o)

%.o : %.c
	$(CC) $(CFLAGS) -c -o $@ $<

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

.PHONY : all clean fclean re

all : $(NAME)

clean :
	rm -rf $(OBJS)

fclean : clean
	rm -rf $(NAME)

re : fclean all
