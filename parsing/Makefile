# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hlabouit <hlabouit@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/19 18:22:58 by hlabouit          #+#    #+#              #
#    Updated: 2023/12/22 20:41:57 by hlabouit         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = parsing
CFILES = main.c libft_.c libft__.c display_errors.c
COFILES = $(CFILES:%.c=%.o)
CC = cc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME) : $(COFILES) #.h
	@$(CC) $(COFILES) -o $(NAME)

%.o : %.c
	@$(CC) $(CFLAGS) $< -c

clean:
	@rm -rf $(COFILES)

fclean: clean
	@rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re