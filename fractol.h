/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aputman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/12 05:06:46 by aputman           #+#    #+#             */
/*   Updated: 2016/06/08 16:03:23 by aputman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "libft/libft.h"
# include "mlx.h"
# include <math.h>

typedef struct		s_env
{
	void			*mlx;
	void			*win;
	void			*img;
	char			mode;
	int				win_x;
	int				win_y;
	int				mouse_x;
	int				mouse_y;
	double			pos_x;
	double			pos_y;
	int				zoom;
	int				rgb;
	int				rgb_line;
	int				endian;
	int				iter;
	struct s_color	*color;
}					t_env;

typedef struct		s_fract
{
	int				x;
	int				y;
	double			rc;
	double			ic;
}					t_fract;

typedef struct		s_color
{
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;
}					t_color;

void				mlx_env_init(t_env *env);
int					input_manager(t_env *env, int keycode);

void				mandelbrot(t_env *env);
void				julia(t_env *env);
void				burningship(t_env *env);
void				draw_mode(t_env *env, char mode);
void				draw_pixel(t_env *env, int x, int y, t_color *color);

void				change_color(t_env *env, t_color *color, int a);
void				put_overlay(t_env *e);

#endif
