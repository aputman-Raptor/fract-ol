/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aputman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/12 09:37:01 by aputman           #+#    #+#             */
/*   Updated: 2016/05/12 12:54:16 by aputman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	fract_j(t_env env, t_fract fr)
{
	double	RZ;
	double	IZ;
	double	R;
	double	I;
	int		a;

	RZ = 1.5 * (fr.x - env.win_x / 2) / (0.5 * env.zoom * env.win_x) +
		env.pos_x;
	IZ = (fr.y - env.win_y / 2) / (0.5 * env.zoom * env.win_y) + env.pos_y;
	a = -1;
	while (++a < (env.iter - 1))
	{
		R = RZ;
		I = IZ;
		RZ = (R * R) - (I * I) + fr.RC;
		IZ = 2 * R * I + fr.IC;
		if ((RZ * RZ + IZ * IZ) > 4)
			break ;
	}
	change_color(env, env.color, a);
	if ((fr.x >= 0 && fr.x < env.win_x) && (fr.y >= 0 && fr.y < env.win_y))
		draw_pixel(env, fr.x, fr.y, env.color);
}

void		julia(t_env env)
{
	t_fract	fr;

	env.img = mlx_new_image(env.mlx, env.win_x, env.win_y);
	fr.RC = -0.7;
	fr.IC = 0.27015;
	fr.y = -1;
	while (++fr.y < env.win_y)
	{
		fr.x = -1;
		while (++fr.x < env.win_x)
			fract_j(env, fr);
	}
	mlx_put_image_to_window(env.mlx, env.win, env.img, 0, 0);
	mlx_destroy_image(env.mlx, env.img);
}
