# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aputman <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/04/09 16:38:05 by aputman           #+#    #+#              #
#    Updated: 2016/06/07 14:13:43 by aputman          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =	fractol

SRC =	fractol.c\
		mlx.c\
		mandelbrot.c\
		julia.c\
		burningship.c\
		keycode.c\
		trucutile.c

OBJ =	$(SRC:.c=.o)

LIB =	libft/libft.a

FLG =	-Wall -Wextra -Werror -Ofast

all: $(NAME)

$(NAME):
	make -C libft
	gcc -c $(FLG) $(SRC)
	gcc -o $(NAME) $(OBJ) $(LIB) -lmlx -framework AppKit -framework OpenGL
	mkdir obj
	mv $(OBJ) obj

clean:
	make clean -C libft
	rm -rf obj

fclean: clean
	make fclean -C libft
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
