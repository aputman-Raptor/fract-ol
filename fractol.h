/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aputman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/12 05:06:46 by aputman           #+#    #+#             */
/*   Updated: 2016/05/12 13:13:06 by aputman          ###   ########.fr       */
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
	double			RC;
	double			IC;
}					t_fract;

typedef struct		s_color
{
	int				r;
	int				g;
	int				b;
}					t_color;

void				mlx_env_init(t_env *env);
void				draw_pixel(t_env env, int x, int y, t_color *color);
void				draw_mode(t_env env, char mode);
void				mandelbrot(t_env env);
void				julia(t_env env);
void				change_color(t_env env, t_color *color, int a);

#endif
