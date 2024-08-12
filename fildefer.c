/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fildefer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alkaram <alkaram@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 17:14:00 by alkaram           #+#    #+#             */
/*   Updated: 2024/05/01 16:36:55 by alkaram          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_fdf	*initialisation(const char *path)
{
	t_fdf	*env;
	char	*title;

	env = (t_fdf *)malloc(sizeof(t_fdf));
	if (!env)
		ft_error("malloc error", 0);
	title = ft_strjoin("fdf - ", path);
	env->mlx = mlx_init();
	if (!env->mlx)
		ft_error("mlx initialisation error", 0);
	env->window = mlx_new_window(env->mlx, WIDTH, HEIGHT, title);
	free(title);
	if (!env->window)
		ft_error("window initialisation error", 0);
	env->image = mlx_new_image(env->mlx, WIDTH, HEIGHT);
	if (!env->image)
		ft_error("image initialisation error", 0);
	env->address = mlx_get_data_addr(env->image, &env->bytes_per_pixel,
			&env->line_size, &env->endian);
	env->map = NULL;
	env->camera = NULL;
	env->mouse = (t_mouse *)malloc(sizeof(t_mouse));
	if (!env->mouse)
		ft_error("malloc mouse error", 0);
	return (env);
}

t_camera	*initialise_camera(t_fdf *env)
{
	t_camera	*camera;

	camera = (t_camera *)malloc(sizeof(t_camera));
	if (!camera)
		ft_error("camera malloc error", 0);
	camera->zoom = minimum(WIDTH / env->map->width / 2, HEIGHT
			/ env->map->height / 2);
	camera->x_angle = -0.615472907;
	camera->y_angle = -0.523599;
	camera->z_angle = 0.615472907;
	camera->z_height = 1;
	camera->x_offset = 0;
	camera->y_offset = 0;
	camera->iso = 1;
	return (camera);
}

t_map	*initialise_map(void)
{
	t_map	*map;

	map = (t_map *)malloc(sizeof(t_map));
	if (!map)
		ft_error("error map alloc", 0);
	map->height = 0;
	map->width = 0;
	map->array = NULL;
	map->z_max = 0;
	map->z_min = 0;
	return (map);
}

int	close_window(void *parameters)
{
	t_fdf	*env;
	int		x;
	int		y;

	env = (t_fdf *)parameters;
	mlx_destroy_image(env->mlx, env->image);
	mlx_destroy_window(env->mlx, env->window);
	free(env->camera);
	free(env->mouse);
	y = -1;
	while (++y < env->map->height)
	{
		x = -1;
		while (++x < env->map->width)
			free(env->map->array[y][x]);
		free(env->map->array[y]);
	}
	free(env->map->array);
	free(env->map);
	free(env->mlx);
	free(env);
	exit(0);
}
