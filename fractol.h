/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aputman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/12 05:06:46 by aputman           #+#    #+#             */
/*   Updated: 2016/08/23 17:09:31 by aputman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "libft/libft.h"
# include "mlx.h"
# include <Opencl/opencl.h>

# define KEY_UP 126
# define KEY_DOWN 125
# define KEY_RIGHT 124
# define KEY_LEFT 123
# define SPACE 49
# define ESC 53
# define NUMPAD_ADD 69
# define NUMPAD_SUB 78
# define PAGE_UP 116
# define PAGE_DOWN 121
# define NUMPAD_1 83
# define NUMPAD_2 84
# define NUMPAD_3 85
# define F1 122
# define F2 120

# define KEY_PRESS_MASK (1L<<0)
# define BUTTON_PRESS_MASK (1L<<2)
# define POINTER_MOTION_MASK (1L<<6)
# define DESTROY_NOTIFY_MASK (1L<<17)

typedef struct		s_env
{
	void			*mlx;
	void			*win;
	void			*img;
	char			*data;
	char			mode;
	int				win_x;
	int				win_y;
	int				mouse_x;
	int				mouse_y;
	long double		pos_x;
	long double		pos_y;
	long double		zoom;
	int				rgb;
	int				rgb_line;
	int				endian;
	int				iter;
	int				lock;
	char			pal;
	struct s_color	*color;
}					t_env;

typedef struct		s_fract
{
	int				x;
	int				y;
	long double		rc;
	long double		ic;
}					t_fract;

typedef struct		s_color
{
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;
}					t_color;

void				mlx_env_init(t_env *env);
int					input_manager(t_env *env, int keycode);
int					ft_exit(t_env *env);

void				mandelbrot(t_env *env);
void				julia(t_env *env);
void				burningship(t_env *env);

void				draw_mode(t_env *env, char mode);
void				draw_pixel(t_env *env, int x, int y, t_color *color);
void				get_color_palette(t_env *e, t_color *color, int a, char c);
void				reset_pos(t_env *env);
int					arg_error(int argc);
void				helper(void);
#endif
