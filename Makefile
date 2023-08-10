# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rkurnava <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/02 14:03:41 by rkurnava          #+#    #+#              #
#    Updated: 2023/02/19 11:00:48 by rkurnava         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =	so_long

CC = cc

CFLAGS =	-Wall -Werror -Wextra

SRC = so_long.c \
	  ./cfiles/map_print.c\
	  ./cfiles/text_handle.c\
	  ./cfiles/event_handle.c\
	  ./cfiles/so_utils.c\
	  ./cfiles/move_handle.c\
      ./map_check/check_map.c \
      ./map_check/check_map_shape.c \
      ./map_check/check_path.c \
      ./map_check/utils.c \
      ./get_next_line/get_next_line.c \
      ./get_next_line/get_next_line_utils.c

all: $(NAME)

OBJ  =	$(SRC:.c=.o)

$(NAME) : $(OBJ)
	@(cd ft_printf && make)
	@cp minilibx-linux/libmlx.a libmlx.a
	@cp ft_printf/libftprintf.a libftprintf.a
	@$(CC) $(OBJ) $(CFLAGS) libmlx.a libftprintf.a -lXext -lX11 -o $(NAME)
	@echo "$(NAME) created"

clean :
	@cd ft_printf && make fclean
	@rm -f $(OBJ)
	@rm -f libmlx.a
	@rm -f libftprintf.a
	@echo "Done cleaning"

fclean : clean
	@rm -f so_long
	@echo "Everything cleaned"

re : fclean all

.PHONY:	all clean fclean re
