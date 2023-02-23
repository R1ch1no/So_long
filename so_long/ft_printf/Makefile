# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rkurnava <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/09 15:09:09 by rkurnava          #+#    #+#              #
#    Updated: 2022/11/09 17:41:36 by rkurnava         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC = ft_printf.c ft_putchar.c ft_putdec.c ft_puthex.c \
		ft_putpoint.c ft_putstr.c ft_putundec.c

CC = cc

CFLAGS = -Werror -Wextra -Wall

OBJ = $(SRC:.c=.o)

$(NAME):
		@$(CC) -c $(CFLAGS) $(SRC)
		@ar crs $(NAME) $(OBJ)
		@echo "$(NAME) created"

all : $(NAME)

clean:
		@rm -f $(OBJ)
		@echo "Objects and $(NAME) deleted"

fclean : clean
		@rm -f $(NAME)

re : fclean all