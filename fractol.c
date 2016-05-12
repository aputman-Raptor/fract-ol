/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aputman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/12 05:08:26 by aputman           #+#    #+#             */
/*   Updated: 2016/05/12 13:12:17 by aputman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		draw_pixel(t_env env, int x, int y, t_color *color)
{
	char	*data;

	data = mlx_get_data_addr(env.img, &env.rgb, &env.rgb_line, &env.endian);
	data[x * env.rgb / 8 + y * env.rgb_line] = (unsigned char)color->b;
	data[x * env.rgb / 8 + 1 + y * env.rgb_line] = (unsigned char)color->g;
	data[x * env.rgb / 8 + 2 + y * env.rgb_line] = (unsigned char)color->r;
}

void		draw_mode(t_env env, char mode)
{
	if (mode == 'M')
		mandelbrot(env);
	else if (mode == 'J')
		julia(env);
	else
		exit (0);
}

int			main(int argc, char **argv)
{
	t_env	env;

	if (argc != 2)
		return (0);
	if ((ft_strcmp("mandelbrot", argv[1])) && (ft_strcmp("julia", argv[1])))
		return (0);
	mlx_env_init(&env);
	if (!(ft_strcmp("mandelbrot", argv[1])))
		env.mode = 'M';
	else if (!(ft_strcmp("julia", argv[1])))
		env.mode = 'J';
	draw_mode(env, env.mode);
	mlx_loop(env.mlx);
	return (0);
}
