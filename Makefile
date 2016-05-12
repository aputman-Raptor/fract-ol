# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aputman <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/04/09 16:38:05 by aputman           #+#    #+#              #
#    Updated: 2016/05/12 10:37:24 by aputman          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =	fractol

SRC =	fractol.c\
		mlx.c\
		mandelbrot.c\
		julia.c\
		trucutile.c

OBJ =	$(SRC:.c=.o)

LIB =	libft/libft.a

FLG =	-Wall -Wextra -Werror -Ofast

all: $(NAME)

$(NAME):
	make -C libft
	gcc -c $(FLG) $(SRC)
	gcc -o $(NAME) $(OBJ) $(LIB) -lmlx -framework AppKit -framework OpenGL

clean:
	make clean -C libft
	rm -f $(OBJ)

fclean: clean
	make fclean -C libft
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
