/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_projection.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alkaram <alkaram@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 20:02:26 by alkaram           #+#    #+#             */
/*   Updated: 2024/05/06 19:19:30 by alkaram          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	draw_instructions(t_fdf *env)
{
	if (env->camera->iso)
		mlx_string_put(env->mlx, env->window, 5, 60, 0xFFFFFF, "S:TP(Cur:Iso)");
	else
		mlx_string_put(env->mlx, env->window, 5, 60, 0xFFFFFF, "S:TP(Cur:Par)");
	mlx_string_put(env->mlx, env->window, 5, 80, 0xFFFFFF, "r:Reset");
	mlx_string_put(env->mlx, env->window, 5, 100, 0xFFFFFF, "-/+:Flatten");
}

void	draw_projection(t_map *map, t_fdf *env)
{
	int	x;
	int	y;

	ft_bzero(env->address, WIDTH * HEIGHT * (env->bytes_per_pixel / 8));
	y = 0;
	if (env->camera->x_angle > 0)
		y = map->height - 1;
	while (y < map->height && y >= 0)
	{
		x = 0;
		if (env->camera->y_angle > 0)
			x = map->width - 1;
		while (x < map->width && x >= 0)
		{
			if (x != map->width - 1)
				draw_line(project(x, y, env), project(x + 1, y, env), env);
			if (y != map->height - 1)
				draw_line(project(x, y, env), project(x, y + 1, env), env);
			x += -2 * (env->camera->y_angle > 0) + 1;
		}
		y += -2 * (env->camera->x_angle > 0) + 1;
	}
	mlx_put_image_to_window(env->mlx, env->window, env->image, 0, 0);
	draw_instructions(env);
}
