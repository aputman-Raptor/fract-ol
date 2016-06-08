/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trucutile.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aputman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/12 06:29:14 by aputman           #+#    #+#             */
/*   Updated: 2016/06/08 16:02:53 by aputman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	change_color(t_env *e, t_color *color, int a)
{
	if (a == (e->iter - 1))
	{
		color->r = 0;
		color->g = 0;
		color->b = 0;
	}
	else
	{
		color->r = (unsigned char)0xFFFFFF / e->iter * a + (a / 0xFFFFFF) + 20;
		color->g = (unsigned char)0xFFFFFF / e->iter * (a % 0xFFFFFF) + 20;
		color->b = (unsigned char)0xFFFFFF / e->iter * a + (a % 0xFFFFFF) + 40;
	}
}
