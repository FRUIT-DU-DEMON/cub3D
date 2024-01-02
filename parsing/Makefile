# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hlabouit <hlabouit@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/19 18:22:58 by hlabouit          #+#    #+#              #
#    Updated: 2024/01/02 04:49:14 by hlabouit         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = parsing
CFILES = main.c check_map_errors.c useful_functions.c display_errors.c libft_functions.c libft_functions2.c
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