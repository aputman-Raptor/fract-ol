/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aputman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/12 05:23:01 by aputman           #+#    #+#             */
/*   Updated: 2016/05/12 13:15:02 by aputman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	key_ft(int keycode, t_env *env)
{
	if (keycode == 53)
		exit(0);
	if (keycode == 123)
		env->pos_x -= 0.01;
	if (keycode == 124)
		env->pos_x += 0.01;
	if (keycode == 125)
		env->pos_y += 0.01;
	if (keycode == 126)
		env->pos_y -= 0.01;
	if (keycode == 78)
	{
		if (env->zoom > 1)
			env->zoom -= 1;
	}
	if (keycode == 69)
		env->zoom += 1;
	draw_mode(*env, env->mode);
	return (1);
}

void		mlx_env_init(t_env *env)
{
	if (!(env->mlx = mlx_init()))
		exit(0);
	env->win_x = 1000;
	env->win_y = 1000;
	env->iter = 50;
	env->pos_x = 0;
	env->pos_y = 0;
	env->zoom = 1;
	if (!(env->color = (t_color *)malloc(sizeof(t_color))))
		exit(0);
	env->win = mlx_new_window(env->mlx, env->win_x, env->win_y, "fractol");
	mlx_key_hook(env->win, key_ft, env);
}
