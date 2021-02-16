/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cisis <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 17:03:54 by cisis             #+#    #+#             */
/*   Updated: 2021/02/16 10:50:52 by cisis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	calculate_delta_dist(t_dda *dda, t_all *all)
{
	dda->map.x = (int)all->plr_pos.x;
	dda->map.y = (int)all->plr_pos.y;
	if (dda->ray.y == 0)
		dda->delta_dist.x = 0;
	else
	{
		if (dda->ray.x == 0)
			dda->delta_dist.x = 1;
		else
			dda->delta_dist.x = fabs(1 / dda->ray.x);
	}
	if (dda->ray.x == 0)
		dda->delta_dist.y = 0;
	else
	{
		if (dda->ray.y == 0)
			dda->delta_dist.y = 1;
		else
			dda->delta_dist.y = fabs(1 / dda->ray.y);
	}
}

static void	calculate_side_dist_and_steps(t_dda *dda, t_all *all)
{
	if (dda->ray.x < 0)
	{
		dda->step_x = -1;
		dda->side_dist.x = (all->plr_pos.x - dda->map.x) * dda->delta_dist.x;
	}
	else
	{
		dda->step_x = 1;
		dda->side_dist.x = (dda->map.x + 1.0 - all->plr_pos.x)
							* dda->delta_dist.x;
	}
	if (dda->ray.y < 0)
	{
		dda->step_y = -1;
		dda->side_dist.y = (all->plr_pos.y - dda->map.y)
							* dda->delta_dist.y;
	}
	else
	{
		dda->step_y = 1;
		dda->side_dist.y = (dda->map.y + 1.0 - all->plr_pos.y)
			* dda->delta_dist.y;
	}
}

static void	perform_dda(t_dda *dda, t_all *all)
{
	dda->hit = 0;
	while (dda->hit == 0)
	{
		if (dda->side_dist.x < dda->side_dist.y)
		{
			dda->side_dist.x += dda->delta_dist.x;
			dda->map.x += dda->step_x;
			dda->side = 0;
		}
		else
		{
			dda->side_dist.y += dda->delta_dist.y;
			dda->map.y += dda->step_y;
			dda->side = 1;
		}
		if (all->parsed.map[dda->map.y][dda->map.x] == '1')
			dda->hit = 1;
	}
	if (dda->side == 0)
		dda->perp_wall_dist = (dda->map.x - all->plr_pos.x
							+ (1 - dda->step_x) / 2) / dda->ray.x;
	else
		dda->perp_wall_dist = (dda->map.y - all->plr_pos.y
							+ (1 - dda->step_y) / 2) / dda->ray.y;
}

int			cast_rays_wall(t_all *all)
{
	t_dda	dda;
	int		x;

	x = 0;
	while (x < all->parsed.res_width)
	{
		dda.camera_x = 2 * x / (double)all->parsed.res_width - 1;
		dda.ray.x = all->plr_pos.dir.x + all->plr_pos.plane.x * dda.camera_x;
		dda.ray.y = all->plr_pos.dir.y + all->plr_pos.plane.y * dda.camera_x;
		calculate_delta_dist(&dda, all);
		calculate_side_dist_and_steps(&dda, all);
		perform_dda(&dda, all);
		draw_wall(x, &dda, all);
		x++;
	}
	return (0);
}
