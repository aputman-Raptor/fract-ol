# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aputman <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/04/09 16:38:05 by aputman           #+#    #+#              #
#    Updated: 2016/08/23 16:59:11 by aputman          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =	fractol

SRC =	fractol.c\
		mlx.c\
		keycode.c\
		trucutile.c\
		mandelbrot.c\
		julia.c\
		burningship.c

OBJ =	$(SRC:.c=.o)

LIB =	libft/libft.a

FLG =	-Wall -Wextra -Werror -Ofast

IMP = -lmlx -framework AppKit -framework OpenGL -framework OpenCL

all: $(NAME)

$(NAME):
	make -C libft
	gcc -c $(FLG) $(SRC)
	gcc -o $(NAME) $(OBJ) $(LIB) $(IMP)
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
