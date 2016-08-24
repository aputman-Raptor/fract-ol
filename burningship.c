/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aputman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/12 05:34:21 by aputman           #+#    #+#             */
/*   Updated: 2016/08/14 16:00:26 by aputman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	fract_bs(t_env *env, t_fract fr)
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
		in1 = 2 * fabs(rn * in) + fr.ic;
		if ((rn1 * rn1 + in1 * in1) > 4)
			break ;
	}
	get_color_palette(env, env->color, a, env->pal);
	if ((fr.x >= 0 && fr.x < env->win_x) && (fr.y >= 0 && fr.y < env->win_y)
			&& a < (env->iter - 1))
		draw_pixel(env, fr.x, fr.y, env->color);
}

void		burningship(t_env *env)
{
	t_fract	fr;

	env->img = mlx_new_image(env->mlx, env->win_x, env->win_y);
	fr.y = -1;
	while (++fr.y < env->win_y)
	{
		fr.x = -1;
		while (++fr.x < env->win_x)
		{
			fr.rc = 2.0 * (fr.x - env->win_x / 2) / (0.5 * env->zoom *
					env->win_x) + env->pos_x;
			fr.ic = (fr.y - env->win_y / 2) / (0.5 * env->zoom * env->win_y)
				+ env->pos_y;
			fract_bs(env, fr);
		}
	}
	mlx_put_image_to_window(env->mlx, env->win, env->img, 0, 0);
	mlx_destroy_image(env->mlx, env->img);
}
