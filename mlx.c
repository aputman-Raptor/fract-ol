/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aputman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/12 05:23:01 by aputman           #+#    #+#             */
/*   Updated: 2016/08/23 19:41:36 by aputman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	key_ft(int keycode, t_env *env)
{
	if ((input_manager(&(*env), keycode)) == 1)
		draw_mode(&(*env), env->mode);
	return (0);
}

static int	ft_mousepointer(int x, int y, t_env *env)
{
	if (env->mode == 'J' && env->lock == 0)
	{
		env->mouse_x = x;
		env->mouse_y = y;
		draw_mode(&(*env), env->mode);
	}
	return (0);
}

static int	ft_mousebutton(int button, int x, int y, t_env *e)
{
	if (button == 1 || button == 4)
	{
		e->pos_x += (2.0 * (((double)x - (e->win_x / 2)) / (e->win_x / 2 *
						e->zoom))) - (2.0 * (((double)x - (e->win_x / 2)) /
						((e->win_x / 2) * (e->zoom * 1.1))));
		e->pos_y += (((double)y - (e->win_y / 2)) / (e->win_y / 2 * e->zoom)) -
			(((double)y - (e->win_y / 2)) / (e->win_y / 2 * (e->zoom * 1.1)));
		e->zoom *= 1.1;
	}
	else if (button == 2 || button == 5)
	{
		if (fabsl(e->zoom) > 1)
		{
			e->pos_x -= (2.0 * (((double)x - (e->win_x / 2)) / (e->win_x / 2 *
							e->zoom / 1.1))) - (2.0 * (((double)x - (e->win_x
									/ 2)) / ((e->win_x / 2) * (e->zoom))));
			e->pos_y -= (((double)y - (e->win_y / 2)) / (e->win_y / 2 *
						e->zoom / 1.1)) - (((double)y - (e->win_y / 2)) /
						(e->win_y / 2 * (e->zoom)));
			e->zoom /= 1.1;
		}
	}
	draw_mode(&(*e), e->mode);
	return (0);
}

static void	mlx_set_hook(t_env *env)
{
	mlx_mouse_hook(env->win, ft_mousebutton, &(*env));
	mlx_hook(env->win, 2, KEY_PRESS_MASK, key_ft, &(*env));
	mlx_hook(env->win, 6, POINTER_MOTION_MASK, ft_mousepointer, &(*env));
	mlx_hook(env->win, 4, BUTTON_PRESS_MASK, ft_mousebutton, &(*env));
	mlx_hook(env->win, 17, DESTROY_NOTIFY_MASK, ft_exit, &(*env));
}

void		mlx_env_init(t_env *env)
{
	if (!(env->mlx = mlx_init()))
		exit(0);
	env->win_x = 1280;
	env->win_y = 720;
	env->iter = 300;
	env->pos_x = 0;
	env->pos_y = 0;
	env->zoom = 1;
	env->lock = 0;
	env->pal = '0';
	if (!(env->color = (t_color *)malloc(sizeof(t_color))))
		exit(0);
	env->win = mlx_new_window(env->mlx, env->win_x, env->win_y, "Fract\'ol");
	mlx_set_hook(&(*env));
}
