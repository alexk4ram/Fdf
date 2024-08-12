/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alkaram <alkaram@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 15:36:53 by alkaram           #+#    #+#             */
/*   Updated: 2024/05/06 15:58:34 by alkaram          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	hook_controls(t_fdf *env)
{
	mlx_hook(env->window, 2, 1, handle_key_press, env);
	mlx_hook(env->window, 17, 1, close_window, env);
}

int	main(int argc, char *argv[])
{
	t_fdf	*env;

	if (argc == 2)
	{
		env = initialisation(argv[1]);
		env->map = initialise_map();
		map_check(argv[1], env->map);
		env->camera = initialise_camera(env);
		hook_controls(env);
		draw_projection(env->map, env);
		mlx_loop(env->mlx);
	}
	else
		ft_error("argument error", 0);
}
