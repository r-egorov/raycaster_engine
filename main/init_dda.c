/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_dda.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cisis <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/26 11:28:17 by cisis             #+#    #+#             */
/*   Updated: 2021/02/26 11:42:51 by cisis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void		init_dda_walls(t_dda_wall *dda)
{
	dda->camera_x = 0;
	dda->ray.x = 0;
	dda->ray.y = 0;
	dda->map.x = 0;
	dda->map.y = 0;
	dda->side_dist.x = 0;
	dda->side_dist.y = 0;
	dda->delta_dist.x = 0;
	dda->delta_dist.y = 0;
	dda->perp_wall_dist = 0;
	dda->step_x = 0;
	dda->step_y = 0;
	dda->hit = 0;
	dda->side = 0;
}

static void		init_dda_floor(t_dda_floor *dda)
{
	dda->x = 0;
	dda->x = 0;
	dda->ray_0.x = 0;
	dda->ray_0.y = 0;
	dda->ray_1.x = 0;
	dda->ray_1.y = 0;
	dda->p = 0;
	dda->row_distance = 0;
	dda->floor_step_x = 0;
	dda->floor_step_y = 0;
	dda->floor_x = 0;
	dda->floor_y = 0;
	dda->cell_x = 0;
	dda->cell_y = 0;
}

static void		init_dda_sprite(t_dda_sprite *dda)
{
	dda->transform_x = 0;
	dda->transform_y = 0;
	dda->sprite_screen_x = 0;
	dda->sprite_height = 0;
	dda->sprite_width = 0;
	dda->draw_start_x = 0;
	dda->draw_start_y = 0;
	dda->draw_end_x = 0;
	dda->draw_end_y = 0;
}

void			init_dda(t_all *all)
{
	init_dda_walls(&(all->dda_walls));
	init_dda_floor(&(all->dda_floor));
	init_dda_sprite(&(all->dda_sprite));
}
