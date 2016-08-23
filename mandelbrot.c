/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aputman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/12 05:34:21 by aputman           #+#    #+#             */
/*   Updated: 2016/06/07 14:16:44 by aputman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	fract_m(t_env *env, t_fract fr)
{
	double	rn1;
	double	in1;
	double	rn;
	double	in;
	int		a;

	rn1 = 0;
	in1 = 0;
	rn = 0;
	in = 0;
	a = -1;
	while (++a < (env->iter - 1))
	{
		rn = rn1;
		in = in1;
		rn1 = rn * rn - in * in + fr.rc;
		in1 = 2 * rn * in + fr.ic;
		if ((rn1 * rn1 + in1 * in1) > 4)
			break ;
	}
	change_color(env, env->color, a);
	if ((fr.x >= 0 && fr.x < env->win_x) && (fr.y >= 0 && fr.y < env->win_y))
		draw_pixel(env, fr.x, fr.y, env->color);
}

void		mandelbrot(t_env *env)
{
	t_fract	fr;

	env->img = mlx_new_image(env->mlx, env->win_x, env->win_y);
	fr.y = -1;
	while (++fr.y < env->win_y)
	{
		fr.x = -1;
		while (++fr.x < env->win_x)
		{
			fr.rc = 2.0 * (fr.x - env->win_x / 2) / (env->zoom *
					env->win_x / 2) + env->pos_x;
			fr.ic = (fr.y - env->win_y / 2) / (0.5 * env->zoom * env->win_y)
				+ env->pos_y;
			fract_m(env, fr);
		}
	}
	mlx_put_image_to_window(env->mlx, env->win, env->img, 0, 0);
	mlx_destroy_image(env->mlx, env->img);
}
