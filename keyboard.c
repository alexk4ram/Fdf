/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alkaram <alkaram@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 16:01:04 by alkaram           #+#    #+#             */
/*   Updated: 2024/05/03 14:57:50 by alkaram          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	reset_camera(t_fdf *env)
{
	float	width_ratio;
	float	height_ratio;

	env->camera->x_offset = 0;
	env->camera->y_offset = 0;
	if (env->camera->iso)
	{
		env->camera->x_angle = -0.615472907;
		env->camera->y_angle = -0.523599;
		env->camera->z_angle = 0.615472907;
	}
	else
	{
		env->camera->x_angle = -0.523599;
		env->camera->y_angle = -0.261799;
		env->camera->z_angle = 0;
	}
	env->camera->z_height = 1;
	width_ratio = (WIDTH / env->map->width / 2);
	height_ratio = (HEIGHT / env->map->height / 2);
	env->camera->zoom = minimum(width_ratio, height_ratio);
}

static void	toggle_projection(t_fdf *env)
{
	if (env->camera->iso)
	{
		env->camera->x_angle = -0.523599;
		env->camera->y_angle = -0.261799;
		env->camera->z_angle = 0;
	}
	else
	{
		env->camera->x_angle = -0.615472907;
		env->camera->y_angle = -0.523599;
		env->camera->z_angle = 0.615472907;
	}
	env->camera->iso = !env->camera->iso;
}

static void	adjust_height(int keycap, t_fdf *env)
{
	if (keycap == MINUS)
		env->camera->z_height += 0.1;
	else if (keycap == PLUS)
		env->camera->z_height -= 0.1;
	if (env->camera->z_height < 0.1)
		env->camera->z_height = 0.1;
	else if (env->camera->z_height > 10)
		env->camera->z_height = 10;
}

static void	move_camera(int keycap, t_fdf *env)
{
	int	move_amount;

	move_amount = 10;
	if (keycap == ARROW_LEFT)
		env->camera->x_offset -= move_amount;
	else if (keycap == ARROW_UP)
		env->camera->y_offset -= move_amount;
	else if (keycap == ARROW_DOWN)
		env->camera->y_offset += move_amount;
	else if (keycap == ARROW_RIGHT)
		env->camera->x_offset += move_amount;
}

int	handle_key_press(int keycap, void *parameters)
{
	t_fdf	*env;

	env = (t_fdf *)parameters;
	if (keycap == ARROW_LEFT || keycap == ARROW_UP || keycap == ARROW_DOWN
		|| keycap == ARROW_RIGHT)
		move_camera(keycap, env);
	else if (keycap == MINUS || keycap == PLUS)
		adjust_height(keycap, env);
	else if (keycap == SPACE)
		toggle_projection(env);
	else if (keycap == KEY_R)
		reset_camera(env);
	else if (keycap == ESCAPE)
		close_window(env);
	draw_projection(env->map, env);
	return (0);
}
