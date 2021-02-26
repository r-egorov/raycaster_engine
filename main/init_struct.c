/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cisis <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 17:14:12 by cisis             #+#    #+#             */
/*   Updated: 2021/02/26 11:57:07 by cisis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void		init_parsed(t_parsed *parsed)
{
	parsed->res_width = 0;
	parsed->res_height = 0;
	parsed->zbuffer = NULL;
	parsed->n_sprites = 0;
	parsed->sprites_list = NULL;
	parsed->sprites = NULL;
	parsed->sprite_order = NULL;
	parsed->sprite_distance = NULL;
	parsed->north_texture_path = NULL;
	parsed->south_texture_path = NULL;
	parsed->west_texture_path = NULL;
	parsed->east_texture_path = NULL;
	parsed->sprite_texture_path = NULL;
	parsed->floor_colour = 0;
	parsed->ceiling_colour = 0;
	parsed->floor_texture_path = NULL;
	parsed->ceiling_texture_path = NULL;
	parsed->map = NULL;
	parsed->player_pos.x = 0;
	parsed->player_pos.y = 0;
	parsed->player_dir = 0;
	parsed->map_height = 0;
	parsed->map_maxwidth = 0;
}

static void		init_window(t_win *window)
{
	window->mlx = NULL;
	window->win = NULL;
	window->frame.img = NULL;
	window->frame.addr = NULL;
	window->frame.line_len = 0;
	window->frame.bpp = 0;
	window->frame.endian = 0;
}

static void		init_keys(t_keys *keys)
{
	keys->w = 0;
	keys->a = 0;
	keys->s = 0;
	keys->d = 0;
	keys->left = 0;
	keys->right = 0;
}

static void		init_plr_pos(t_plr_pos *plr_pos)
{
	plr_pos->x = 0;
	plr_pos->y = 0;
	plr_pos->z = 0;
	plr_pos->dir.x = 0;
	plr_pos->dir.y = 0;
	plr_pos->plane.x = 0;
	plr_pos->plane.y = 0;
}

void			init_struct(t_all *all)
{
	init_parsed(&(all->parsed));
	init_window(&(all->window));
	init_keys(&(all->keys));
	init_plr_pos(&(all->plr_pos));
	init_dda(all);
	init_txtrs(&(all->txtrs));
}
