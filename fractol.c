/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aputman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/12 05:08:26 by aputman           #+#    #+#             */
/*   Updated: 2016/08/23 17:24:14 by aputman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		draw_pixel(t_env *env, int x, int y, t_color *color)
{
	char	*data;

	data = mlx_get_data_addr(env->img, &env->rgb, &env->rgb_line, &env->endian);
	data[x * env->rgb / 8 + y * env->rgb_line] = color->b;
	data[x * env->rgb / 8 + 1 + y * env->rgb_line] = color->g;
	data[x * env->rgb / 8 + 2 + y * env->rgb_line] = color->r;
}

void		draw_mode(t_env *env, char mode)
{
	if (mode == 'M')
		mandelbrot(&(*env));
	else if (mode == 'J')
		julia(&(*env));
	else if (mode == 'B')
		burningship(&(*env));
}

int			main(int argc, char **argv)
{
	t_env	*env;

	if (argc != 2)
		arg_error(argc);
	if (!(env = (t_env *)ft_memalloc(sizeof(t_env))))
		return (-1);
	if ((ft_strcmp("mandelbrot", argv[1])) && (ft_strcmp("julia", argv[1]))
				&& (ft_strcmp("burningship", argv[1])))
		return (arg_error(argc));
	mlx_env_init(&(*env));
	if (!(ft_strcmp("mandelbrot", argv[1])))
		env->mode = 'M';
	else if (!(ft_strcmp("julia", argv[1])))
		env->mode = 'J';
	else if (!(ft_strcmp("burningship", argv[1])))
		env->mode = 'B';
	draw_mode(env, env->mode);
	helper();
	mlx_loop(env->mlx);
	return (0);
}
