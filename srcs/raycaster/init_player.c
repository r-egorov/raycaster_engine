/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cisis <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 18:21:14 by cisis             #+#    #+#             */
/*   Updated: 2021/02/12 18:32:14 by cisis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	north(t_all *all)
{
	all->plr_pos.dir.x = 0;
	all->plr_pos.dir.y = -1;
	all->plr_pos.plane.x = -0.66;
	all->plr_pos.plane.y = 0;
}

static void	south(t_all *all)
{
	all->plr_pos.dir.x = 0;
	all->plr_pos.dir.y = 1;
	all->plr_pos.plane.x = 0.66;
	all->plr_pos.plane.y = 0;
}

static void	west(t_all *all)
{
	all->plr_pos.dir.x = -1;
	all->plr_pos.dir.y = 0;
	all->plr_pos.plane.x = 0;
	all->plr_pos.plane.y = 0.66;
}

static void	east(t_all *all)
{
	all->plr_pos.dir.x = 1;
	all->plr_pos.dir.y = 0;
	all->plr_pos.plane.x = 0;
	all->plr_pos.plane.y = -0.66;
}

void		init_player_position(t_all *all)
{
	all->plr_pos.x = all->parsed.player_pos.x + 0.5;
	all->plr_pos.y = all->parsed.player_pos.y + 0.5;
	if (all->parsed.player_dir == 'N')
		north(all);
	else if (all->parsed.player_dir == 'S')
		south(all);
	else if (all->parsed.player_dir == 'W')
		west(all);
	else if (all->parsed.player_dir == 'E')
		east(all);
}
