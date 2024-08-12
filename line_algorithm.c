/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_algorithm.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alkaram <alkaram@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 18:52:31 by alkaram           #+#    #+#             */
/*   Updated: 2024/04/25 21:20:58 by alkaram          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	lin_int(int first, int second, float p)
{
	if (first == second)
		return (first);
	return ((int)((double)first + (second - first) * p));
}

static int	gc(int x, t_point s, t_point e, float factor)
{
	int		r;
	int		g;
	int		b;
	float	percent;

	percent = absolute(x - s.x) / absolute(e.x - s.x);
	if (s.reverse)
	{
		r = lin_int((e.colour >> 16) & 0xFF, (s.colour >> 16) & 0xFF, percent);
		g = lin_int((e.colour >> 8) & 0xFF, (s.colour >> 8) & 0xFF, percent);
		b = lin_int(e.colour & 0xFF, s.colour & 0xFF, percent);
	}
	else
	{
		r = lin_int((s.colour >> 16) & 0xFF, (e.colour >> 16) & 0xFF, percent);
		g = lin_int((s.colour >> 8) & 0xFF, (e.colour >> 8) & 0xFF, percent);
		b = lin_int(s.colour & 0xFF, e.colour & 0xFF, percent);
	}
	r *= factor;
	g *= factor;
	b *= factor;
	return ((r << 16) | (g << 8) | b);
}

static void	ft_swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

static void	draw_line_loop(t_point s, t_point e, float gradient, t_fdf *env)
{
	float	inter_y;
	int		x;

	inter_y = (float)s.y;
	x = s.x;
	while (x <= e.x)
	{
		if (env->steep)
		{
			pp_c(env, int_part(inter_y), x, gc(x, s, e, rfp(inter_y)));
			pp_c(env, int_part(inter_y) + 1, x, gc(x, s, e, fp(inter_y)));
		}
		else
		{
			pp_c(env, x, int_part(inter_y), gc(x, s, e, rfp(inter_y)));
			pp_c(env, x, int_part(inter_y) + 1, gc(x, s, e, fp(inter_y)));
		}
		inter_y += gradient;
		x++;
	}
}

void	draw_line(t_point start, t_point end, t_fdf *env)
{
	float	delta_y;
	float	delta_x;
	float	gradient;

	env->steep = absolute(end.y - start.y) > absolute(end.x - start.x);
	if (env->steep)
	{
		ft_swap(&start.x, &start.y);
		ft_swap(&end.x, &end.y);
	}
	if (start.x > end.x)
	{
		ft_swap(&start.x, &end.x);
		ft_swap(&start.y, &end.y);
		start.reverse = 1;
	}
	delta_x = (float)(end.x - start.x);
	delta_y = (float)(end.y - start.y);
	gradient = delta_y / delta_x;
	if (delta_x == 0.0f)
		gradient = 1.f;
	draw_line_loop(start, end, gradient, env);
}
