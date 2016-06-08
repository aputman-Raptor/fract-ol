/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keycode.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aputman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/07 13:48:03 by aputman           #+#    #+#             */
/*   Updated: 2016/06/08 16:04:22 by aputman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	pos_key(t_env *env, int keycode)
{
	if (keycode == 49)
	{
		env->zoom = 1;
		env->pos_x = 0;
		env->pos_y = 0;
	}
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
}

static void	zoom_key(t_env *env, int keycode)
{
	if (keycode == 69)
	{
		if (env->zoom >= 500)
			env->zoom += 100;
		else
			env->zoom += 1;
	}
	if (keycode == 78)
	{
		if (env->zoom >= 500)
			env->zoom -= 100;
		else
			env->zoom -= 1;
	}
}

int			input_manager(t_env *env, int keycode)
{
	if (keycode == 49 || keycode == 53 || (keycode >= 123 && keycode <= 126))
	{
		pos_key(&(*env), keycode);
		return (1);
	}
	if (keycode == 69 || keycode == 78)
	{
		zoom_key(&(*env), keycode);
		return (1);
	}
	return (0);
}
