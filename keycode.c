/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keycode.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aputman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/07 13:48:03 by aputman           #+#    #+#             */
/*   Updated: 2016/08/18 17:21:45 by aputman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	pos_key(t_env *env, int keycode)
{
	if (keycode == SPACE)
		reset_pos(&(*env));
	else if (keycode == ESC)
		ft_exit(env);
	else if (keycode == F2)
	{
		if (env->lock == 0 && env->mode == 'J')
			env->lock = 1;
		else if (env->lock == 1 && env->mode == 'J')
			env->lock = 0;
	}
	else if (keycode == KEY_LEFT)
		env->pos_x -= 0.1 / env->zoom;
	else if (keycode == KEY_RIGHT)
		env->pos_x += 0.1 / env->zoom;
	else if (keycode == KEY_DOWN)
		env->pos_y += 0.1 / env->zoom;
	else if (keycode == KEY_UP)
		env->pos_y -= 0.1 / env->zoom;
	else
		return (0);
	return (1);
}

static int	zoom_key(t_env *env, int keycode)
{
	if (keycode == NUMPAD_ADD)
		env->zoom *= 1.1;
	else if (keycode == NUMPAD_SUB)
	{
		if (fabsl(env->zoom) > 1)
			env->zoom /= 1.1;
		if (fabsl(env->zoom) < 1)
			env->zoom = 1;
	}
	else
		return (0);
	return (1);
}

static int	switch_key(t_env *env, int keycode)
{
	if (keycode == NUMPAD_1)
		env->mode = 'M';
	else if (keycode == NUMPAD_2)
		env->mode = 'J';
	else if (keycode == NUMPAD_3)
		env->mode = 'B';
	else if (keycode == F1)
	{
		reset_pos(&(*env));
		env->zoom *= -1;
	}
	else if (keycode == PAGE_UP)
	{
		if (env->pal != '0')
			env->pal -= 1;
	}
	else if (keycode == PAGE_DOWN)
	{
		if (env->pal != '1')
			env->pal += 1;
	}
	else
		return (0);
	return (1);
}

int			input_manager(t_env *env, int keycode)
{
	if (pos_key(&(*env), keycode) || zoom_key(&(*env), keycode)
			|| switch_key(&(*env), keycode))
		return (1);
	else
		return (0);
}
