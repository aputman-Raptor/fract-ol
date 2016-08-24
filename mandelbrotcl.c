/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrotcl.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aputman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/23 19:59:57 by aputman           #+#    #+#             */
/*   Updated: 2016/08/23 20:24:00 by aputman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*fract_m(__global char *data, __private int iteration,
		__private double rc, __private double ic)
{
	return (data);
}

__kernel void	mandelbrot(__global double zoom, __global int iteration,
								 __global int win_x, __global int win_y,
								 __global int pos_x, __global int pos_y,
								 __global char *data)
{
	__private double	rc;
	__private double	ic;
	__private int		i;
	__private int		j;
	__private uint		id;

	id = get_global_id(0);
	i = -1 + (10 * id);
	while (++i < (10 * (id + 1)))
	{
		j = -1;
		while (++j < win_y)
		{
			rc = 2.0 * (i - (win_x / 2)) / (zoom * win_x / 2) + pos_x;
			ic = (j - (win_y / 2)) / (zoom * win_y / 2) + pos_y;
			fract_m(iteration, rc, ic);
		}
	}
}
