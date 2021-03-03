/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floor_ceiling_raycasting.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cisis <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 10:48:18 by cisis             #+#    #+#             */
/*   Updated: 2021/02/25 13:10:34 by cisis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	calculate_vars(t_all *all, t_dda_floor *dda_floor)
{
	double		row_distance;
	int			p;

	dda_floor->ray_0.x = all->plr_pos.dir.x - all->plr_pos.plane.x;
	dda_floor->ray_0.y = all->plr_pos.dir.y - all->plr_pos.plane.y;
	dda_floor->ray_1.x = all->plr_pos.dir.x + all->plr_pos.plane.x;
	dda_floor->ray_1.y = all->plr_pos.dir.y + all->plr_pos.plane.y;
	p = dda_floor->y - all->parsed.res_height / 2;
	all->plr_pos.z = 0.5 * all->parsed.res_height;
	row_distance = all->plr_pos.z / p;
	dda_floor->floor_step_x = row_distance
		* (dda_floor->ray_1.x - dda_floor->ray_0.x) / all->parsed.res_width;
	dda_floor->floor_step_y = row_distance
		* (dda_floor->ray_1.y - dda_floor->ray_0.y) / all->parsed.res_width;
	dda_floor->floor_x = all->plr_pos.x + row_distance * dda_floor->ray_0.x;
	dda_floor->floor_y = all->plr_pos.y + row_distance * dda_floor->ray_0.y;
}

static void	draw_floor_texture(t_dda_floor *dda_floor, t_all *all)
{
	int				tx;
	int				ty;
	unsigned int	colour;

	tx = (int)(all->txtrs.floor.width
	* (dda_floor->floor_x - dda_floor->cell_x));
	ty = (int)(all->txtrs.floor.height
	* (dda_floor->floor_y - dda_floor->cell_y));
	colour = *(unsigned int*)(all->txtrs.floor.addr
			+ (ty * all->txtrs.floor.line_len
			+ tx * (all->txtrs.floor.bpp / 8)));
	colour = (colour >> 1) & 8355711;
	my_mlx_pixel_put(&(all->window.frame),
			dda_floor->x, dda_floor->y, colour);
}

static void	draw_ceiling_texture(t_dda_floor *dda_floor, t_all *all)
{
	int				tx;
	int				ty;
	unsigned int	colour;

	tx = (int)(all->txtrs.ceiling.width
			* (dda_floor->floor_x - dda_floor->cell_x));
	ty = (int)(all->txtrs.ceiling.height
			* (dda_floor->floor_y - dda_floor->cell_y));
	colour = *(unsigned int*)(all->txtrs.ceiling.addr
			+ (ty * all->txtrs.ceiling.line_len
			+ tx * (all->txtrs.ceiling.bpp / 8)));
	colour = (colour >> 1) & 8355711;
	my_mlx_pixel_put(&(all->window.frame),
			dda_floor->x, all->parsed.res_height - dda_floor->y - 1, colour);
}

int			cast_rays_floor_ceiling(t_all *all)
{
	t_dda_floor	*dda;

	dda = &all->dda_floor;
	dda->y = 0;
	while (dda->y < all->parsed.res_height)
	{
		calculate_vars(all, dda);
		dda->x = all->parsed.res_width - 1;
		while (dda->x >= 0)
		{
			dda->cell_x = (int)dda->floor_x;
			dda->cell_y = (int)dda->floor_y;
			dda->floor_x += dda->floor_step_x;
			dda->floor_y += dda->floor_step_y;
			draw_floor_texture(dda, all);
			draw_ceiling_texture(dda, all);
			dda->x--;
		}
		dda->y++;
	}
	return (0);
}
