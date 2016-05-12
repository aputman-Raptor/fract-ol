/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trucutile.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aputman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/12 06:29:14 by aputman           #+#    #+#             */
/*   Updated: 2016/05/12 12:48:47 by aputman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		change_color(t_env env, t_color *color, int a)
{
	if (a < (env.iter / 3))
	{
		color->r = ((0xFFFFFF / env.iter) * a);
		color->g = 0;
		color->b = 0;
	}
	else if (a >= (env.iter / 3) && a < ((env.iter / 3) * 2))
	{
		color->r = 0;
		color->g = ((0xFFFFFF / env.iter) * a);
		color->b = 0;
	}
	else if (a >= ((env.iter / 3) * 2) && a < env.iter)
	{
		color->r = 0;
		color->g = 0;
		color->b = ((0xFFFFFF / env.iter) * a);
	}
}
