/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trucutile.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aputman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/12 06:29:14 by aputman           #+#    #+#             */
/*   Updated: 2016/08/18 17:22:21 by aputman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	reset_pos(t_env *env)
{
	env->zoom /= fabsl(env->zoom);
	env->pos_x = 0;
	env->pos_y = 0;
	env->iter = 300;
}

int		arg_error(int argc)
{
	if (argc == 1)
		ft_putstr("\033[31mNo argument found, ");
	else if (argc == 2)
		ft_putstr("\033[31mInvalid argument, ");
	else
		ft_putstr("\033[31mToo much arguments, ");
	ft_putstr("please enter only 1 argument, the valid arguments are:\033[m");
	ft_putstr("\033[32m\nmandelbrot\njulia\nburningship\n\033[m");
	exit(0);
	return (-1);
}

void	helper(void)
{
	ft_putstr("\033[32mF1 : Reverse the fractal (except julia)\n");
	ft_putstr("F2 : Lock julia params\n");
	ft_putstr("Arrows to move and +/- to zoom/dezoom\n");
	ft_putstr("1-3 To switch between fractals\n");
	ft_putstr("Space to reset to initial state (keep the reversed mode)\n");
	ft_putstr("PAGE_UP / PAGE DOWN to switch color\n\033[m");
}

int		ft_exit(t_env *env)
{
	free(env->color);
	mlx_destroy_window(env->mlx, env->win);
	free(env);
	exit(0);
	return (0);
}

void	get_color_palette(t_env *e, t_color *color, int a, char c)
{
	if (c == '0')
		color->g = (unsigned char)0xFFFFFF / e->iter * (a % 0xFFFFFF) + 20;
	else
		color->g = (unsigned char)0xFFFFFF / e->iter * a + (a % 0xFFFFFF) + 20;
	color->r = (unsigned char)0xFFFFFF / e->iter * a + (a / 0xFFFFFF) + 20;
	color->b = (unsigned char)0xFFFFFF / e->iter * a + (a % 0xFFFFFF) + 40;
}
