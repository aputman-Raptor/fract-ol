/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aputman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/12 05:23:01 by aputman           #+#    #+#             */
/*   Updated: 2016/06/08 16:03:01 by aputman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	key_ft(int keycode, t_env *env)
{
	if ((input_manager(&(*env), keycode)) == 1)
		draw_mode(env, env->mode);
	return (0);
}

static int	ft_mousepointer(int x, int y, t_env *env)
{
	env->mouse_x = x;
	env->mouse_y = y;
	draw_mode(env, env->mode);
	return (0);
}

static int	ft_mousebutton(int button, int x, int y, t_env *env)
{
	x = 0;
	y = 0;
	if (button == 1)
		env->zoom += 1;
	else if (button == 2)
	{
		if (env->zoom > 1)
			env->zoom -= 1;
	}
	draw_mode(env, env->mode);
	return (0);
}

void		mlx_env_init(t_env *env)
{
	if (!(env->mlx = mlx_init()))
		exit(0);
	env->win_x = 1280;
	env->win_y = 720;
	env->iter = 200;
	env->pos_x = 0;
	env->pos_y = 0;
	env->zoom = 1;
	if (!(env->color = (t_color *)malloc(sizeof(t_color))))
		exit(0);
	env->win = mlx_new_window(env->mlx, env->win_x, env->win_y, "Fract\'ol");
	mlx_mouse_hook(env->win, ft_mousebutton, env);
	mlx_hook(env->win, 2, 1, key_ft, env);
	mlx_hook(env->win, 6, 64, ft_mousepointer, env);
}
