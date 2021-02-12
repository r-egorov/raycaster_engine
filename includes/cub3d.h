/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cisis <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 15:48:12 by cisis             #+#    #+#             */
/*   Updated: 2021/02/12 17:50:54 by cisis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "libft.h"
# include <mlx.h>
# include <math.h>
# include <fcntl.h>
# include <stdio.h>
# include <string.h>
# include <errno.h>
# define SCALE 30
# define WHITE 0x00FFFFFF
# define RED 0x00FF0000
# define GREEN 0x0000FF00
# define PI 3.1415926535

int				g_errno;
int				g_screen_height;
int				g_screen_width;

typedef struct	s_point
{
	int			x;
	int			y;
}				t_point;

typedef struct	s_vector
{
	double		x;
	double		y;
}				t_vector;

typedef struct	s_plr_pos
{
	double		x;
	double		y;
	t_vector	dir;
	t_vector	plane;
}				t_plr_pos;

typedef struct	s_parsed
{
	int						res_width;
	int						res_height;
	char					*north_texture_path;
	char					*south_texture_path;
	char					*west_texture_path;
	char					*east_texture_path;
	char					*sprite_texture_path;
	unsigned int			floor_colour;
	unsigned int			ceiling_colour;
	char					**map;
	t_point					player_pos;
	char					player_dir;
	size_t					map_height;
	size_t					map_maxwidth;
}				t_parsed;

typedef struct	s_img
{
	void		*img;
	char		*addr;
	int			bpp;
	int			line_len;
	int			endian;
	int			height;
	int			width;
}				t_img;

typedef struct	s_win
{
	void		*mlx;
	void		*win;
	t_img		frame;
}				t_win;

typedef struct	s_keys
{
	int			w;
	int			a;
	int			s;
	int			d;
	int			left;
	int			right;
}				t_keys;

typedef struct	s_dda
{
	double		camera_x;
	t_vector	ray;
	t_point		map;
	t_vector	side_dist;
	t_vector	delta_dist;
	double		perp_wall_dist;
	int			step_x;
	int			step_y;
	int			hit;
	int			side;
}				t_dda;

typedef struct	s_txtrs
{
	t_img		north;
	t_img		south;
	t_img		west;
	t_img		east;
	t_img		sprite;
}				t_txtrs;

typedef struct	s_all
{
	t_parsed	parsed;
	t_win		window;
	t_keys		keys;
	t_plr_pos	plr_pos;
	t_dda		dda;
	t_txtrs		txtrs;
}				t_all;

typedef struct	s_ver_line
{
	int			height;
	int			draw_start;
	int			draw_finish;
}				t_ver_line;

typedef struct	s_column
{
	t_ver_line	line;
	double		texture_pos;
	int			texture_x;
	int			texture_y;
	double		step;
}				t_column;

void			init_struct(t_all *all);
int				parse_file(char *filepath, t_parsed *parsed);
int				process_error(void);
int				validate_list(t_parsed *parsed, t_list *lst);
int				validate_parameter(void *content, t_parsed *parsed);
void			validate_resolution(char **parameters, t_parsed *parsed);
void			validate_texture(char **parameters, t_parsed *parsed, int mode);
void			validate_colour(char **parameters, t_parsed *parsed, int mode);
void			validate_map(t_list **begin, t_parsed *parsed);
int				valid_space_map(t_parsed *parsed, size_t x, size_t y);
int				valid_zero_map(t_parsed *parsed, size_t x, size_t y);
void			free_str(void *line);
void			free_strs(char **strs);
void			free_parsed(t_parsed *parsed);
int				valid_number_params(char **parameters, size_t num_params);

int				get_textures(t_all *all);

void			my_mlx_pixel_put(t_img *img, int x, int y, int color);
void			draw_map(t_all *all);
void			draw_player(t_all *all, int colour);
int				render_next_frame(t_all *all);
void			draw_column(int x, t_dda *dda, t_all *all);
void			draw_ceiling(t_all *all, int x, t_ver_line line,
							unsigned int colour);
void			draw_floor(t_all *all, int x, t_ver_line line,
							unsigned int colour);

int				infinite_hook(t_all *all);
int				key_pressed_hook(int keycode, t_all *all);
int				key_released_hook(int keycode, t_all *all);

int				calculate_plr_pos(t_all *all);

int				cast_rays(t_all *all);
#endif
