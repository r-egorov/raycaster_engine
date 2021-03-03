/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cisis <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 15:48:12 by cisis             #+#    #+#             */
/*   Updated: 2021/03/03 13:04:02 by cisis            ###   ########.fr       */
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
# define MOV_SPEED 0.1
# define ROT_SPEED 0.05
# define SCREEN_HEIGHT 1440
# define SCREEN_WIDTH 2560 

int				g_errno;
int				g_screen_height;
int				g_screen_width;

typedef struct	s_point
{
	int			x;
	int			y;
}				t_point;

typedef struct	s_fpoint
{
	double		x;
	double		y;
}				t_fpoint;

typedef struct	s_vector
{
	double		x;
	double		y;
}				t_vector;

typedef struct	s_plr_pos
{
	double		x;
	double		y;
	double		z;
	t_vector	dir;
	t_vector	plane;
}				t_plr_pos;

typedef struct	s_parsed
{
	int						res_width;
	int						res_height;
	double					*zbuffer;
	int						n_sprites;
	t_list					*sprites_list;
	t_fpoint				*sprites;
	int						*sprite_order;
	double					*sprite_distance;
	char					*north_texture_path;
	char					*south_texture_path;
	char					*west_texture_path;
	char					*east_texture_path;
	char					*sprite_texture_path;
	unsigned int			floor_colour;
	unsigned int			ceiling_colour;
	char					*floor_texture_path;
	char					*ceiling_texture_path;
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

typedef struct	s_dda_sprite
{
	double		transform_x;
	double		transform_y;
	int			sprite_screen_x;
	int			sprite_height;
	int			sprite_width;
	int			draw_start_x;
	int			draw_start_y;
	int			draw_end_x;
	int			draw_end_y;
}				t_dda_sprite;

typedef struct	s_dda_floor
{
	int			x;
	int			y;
	t_vector	ray_0;
	t_vector	ray_1;
	int			p;
	double		row_distance;
	double		floor_step_x;
	double		floor_step_y;
	double		floor_x;
	double		floor_y;
	int			cell_x;
	int			cell_y;
}				t_dda_floor;

typedef struct	s_dda_wall
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
	double		*zbuffer;
}				t_dda_wall;

typedef struct	s_txtrs
{
	t_img		north;
	t_img		south;
	t_img		west;
	t_img		east;
	t_img		sprite;
	t_img		floor;
	t_img		ceiling;
}				t_txtrs;

typedef struct	s_all
{
	int				save;
	t_parsed		parsed;
	t_win			window;
	t_keys			keys;
	t_plr_pos		plr_pos;
	t_txtrs			txtrs;
	t_dda_wall		dda_walls;
	t_dda_floor		dda_floor;
	t_dda_sprite	dda_sprite;
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
void			init_dda(t_all *all);
void			init_txtrs(t_txtrs *txtrs);

int				parse_file(char *filepath, t_parsed *parsed);
int				process_error(void);
int				validate_list(t_parsed *parsed, t_list *lst);
int				validate_parameters(t_list **head, t_parsed *parsed);
void			validate_resolution(char **parameters, t_parsed *parsed);
void			validate_texture(char **parameters, t_parsed *parsed, int mode);
void			validate_colour(char **parameters, t_parsed *parsed, int mode);
void			validate_map(t_list **begin, t_parsed *parsed);
int				valid_space_map(t_parsed *parsed, int x, int y);
int				valid_zero_map(t_parsed *parsed, int x, int y);
void			free_str(void *line);
void			free_strs(char **strs);
void			free_parsed(t_parsed *parsed);
int				valid_number_params(char **parameters, size_t num_params);
int				append_sprite(t_parsed *parsed, int x, int y);
void			make_sprite_arrays(t_parsed *parsed);

int				get_textures(t_all *all);

void			my_mlx_pixel_put(t_img *img, int x, int y, int color);
void			draw_map(t_all *all);
void			draw_player(t_all *all, int colour);
int				render_next_frame(t_all *all);
void			draw_wall(int x, t_dda_wall *dda, t_all *all);
void			draw_ceiling(t_all *all);
void			draw_floor(t_all *all);

int				infinite_hook(t_all *all);
int				key_pressed_hook(int keycode, t_all *all);
int				key_released_hook(int keycode, t_all *all);

int				calculate_plr_pos(t_all *all);
void			init_player_position(t_all *all);

int				cast_rays_wall(t_all *all);
int				cast_rays_floor_ceiling(t_all *all);
int				cast_sprites(t_all *all);
void			draw_sprite(t_all *all, t_dda_sprite *dda);

int				make_screenshot(t_all *all);
int				close_window(t_all *all);
#endif
