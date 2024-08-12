/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alkaram <alkaram@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 00:10:34 by alkaram           #+#    #+#             */
/*   Updated: 2024/05/09 19:50:34 by alkaram          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "get_next_line/get_next_line.h"
# include "libft/libft.h"
# include "minilibx-linux/mlx.h"
# include <errno.h>
# include <fcntl.h>
# include <math.h>
# include <stdio.h>
# include <unistd.h>

# define WIDTH 1920
# define HEIGHT 1080

# define RED 16
# define GREEN 8
# define BLUE 0

# define ARROW_LEFT 65361
# define ARROW_RIGHT 65363
# define ARROW_DOWN 65364
# define ARROW_UP 65362
# define MINUS 45
# define PLUS 61
# define SPACE 32
# define KEY_R 114
# define MOUSE_CLICK_LEFT 1
# define MOUSE_CLICK_RIGHT 3
# define MOUSE_CLICK_MIDDLE 2
# define MOUSE_WHEEL_UP 4
# define MOUSE_WHEEL_DOWN 5
# define ESCAPE 65307
# define ZOOM_INCREMENT 2
# define MIN_ZOOM 1

typedef struct s_point
{
	int			x;
	int			y;
	int			z;
	int			colour;
	int			reverse;
}				t_point;

typedef struct s_map
{
	int			height;
	int			width;
	int			***array;
	int			z_max;
	int			z_min;
}				t_map;

typedef struct s_camera
{
	int			zoom;
	float		x_angle;
	float		y_angle;
	float		z_angle;
	float		z_height;
	int			x_offset;
	int			y_offset;
	int			iso;
}				t_camera;

typedef struct s_mouse
{
	int			button;
	int			x;
	int			y;
	int			previous_x;
	int			previous_y;
}				t_mouse;

typedef struct s_fdf
{
	void		*mlx;
	void		*window;
	void		*image;
	char		*address;
	int			bytes_per_pixel;
	int			line_size;
	int			endian;
	int			steep;
	t_map		*map;
	t_camera	*camera;
	t_mouse		*mouse;
}				t_fdf;

// static int		get_height(char *file);
// static int		get_width(char *file);
void			ft_error(char *error_message, int system_function);
// static void		fill_map(int **map, const char *line, int width);
int				ft_puthex(char *hexstring);
// static void		get_zmin_zmax(t_map *map);
void			map_check(char *filename, t_map *map);
void			pp_c(t_fdf *env, int x, int y, int colour);
int				colourisation(int z, t_map *map);
t_point			project(int x, int y, t_fdf *env);
t_point			translate_point(t_point point, t_fdf *env);
t_point			rotate_point(t_point point, t_fdf *env);
t_point			scale_point(int x, int y, t_fdf *env);
// static void		rotate_x(int *y, int *z, float x_angle);
// static void		rotate_y(int *x, int *z, float y_angle);
// static void		rotate_z(int *x, int *y, float z_angle);
void			draw_projection(t_map *map, t_fdf *env);
int				minimum(int a, int b);
void			rotate_x(int *y, int *z, float x_angle);
void			rotate_y(int *x, int *z, float y_angle);
void			rotate_z(int *x, int *y, float z_angle);
float			rotation_angles(float angle);
// void			mouse_zoom(int button, t_fdf *env);
// static void		update_and_draw(t_fdf *env, int x, int y);
// int				mouse_move(int x, int y, void *parameters);
// int				mouse_click(int button);
// int				mouse_down(int button, int x, int y, void *parameters);
// int				mouse_up(int button, int x, int y, void *parameters);
// void			mouse_move_z(int x, int y, t_fdf *env);
// static void		reset_camera(t_fdf *env);
// static void		toggle_projection(t_fdf *env);
// static void		adjust_height(int keycap, t_fdf *env);
// static void		move_camera(int keycap, t_fdf *env);
int				handle_key_press(int keycap, void *parameters);
t_fdf			*initialisation(const char *path);
t_camera		*initialise_camera(t_fdf *env);
t_map			*initialise_map(void);
float			absolute(float n);
int				int_part(float n);
float			fp(float n);
float			rfp(float n);
// static int		lin_int(int first, int second, float p);
// static int		gc(int x, t_point s, t_point e, float factor);
// static void		ft_swap(int *a, int *b);
// static void		draw_line_loop(t_point s, t_point e, float gradient,
// 					t_fdf *env);
void			draw_line(t_point start, t_point end, t_fdf *env);
int				close_window(void *parameters);
void			hook_controls(t_fdf *env);
void			draw_lines(int x, int y, t_map *map, t_fdf *env);

#endif