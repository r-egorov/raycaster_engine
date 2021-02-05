/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cisis <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 17:14:12 by cisis             #+#    #+#             */
/*   Updated: 2021/02/05 19:17:46 by cisis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void		init_parsed(t_parsed *parsed)
{
	parsed->res_width = 0;
	parsed->res_height = 0;
	parsed->north_texture_path = NULL;
	parsed->south_texture_path = NULL;
	parsed->west_texture_path = NULL;
	parsed->east_texture_path = NULL;
	parsed->sprite_texture_path = NULL;
	parsed->floor_colour = 0;
	parsed->ceiling_colour = 0;
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
	window->img = NULL;
	window->addr = NULL;
	window->line_len = 0;
	window->bpp = 0;
	window->endian = 0;
}

static void		init_keys(t_keys *keys)
{
	keys->w = 0;
	keys->a = 0;
	keys->s = 0;
	keys->d = 0;
}

static void		init_plr_pos(t_plr_pos *plr_pos)
{
	plr_pos->x = 0;
	plr_pos->y = 0;
	plr_pos->dirx = 0;
	plr_pos->diry = 0;
}

static void		init_dda(t_dda *dda)
{
	dda->mapx = 0;
	dda->mapy = 0;
}

void			init_struct(t_all *all)
{
	init_parsed(&(all->parsed));
	init_window(&(all->window));
	init_keys(&(all->keys));
	init_plr_pos(&(all->plr_pos));
	init_dda(&(all->dda));
}
