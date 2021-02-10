/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cisis <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 17:03:54 by cisis             #+#    #+#             */
/*   Updated: 2021/02/09 11:35:51 by cisis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int			cast_rays(t_all *all)
{
	double	planex;
	double	planey;

	planex = 0;
	planey = 0.66;

	/*
	double	time;
	double	oldtime;

	time = 0;
	oldtime = 0;
	*/

	int		x;

	x = 0;

	double	camerax;
	double	raydirx;
	double	raydiry;

	while (x < all->parsed.res_width)
	{
		camerax = 2 * x / (double)all->parsed.res_width - 1;
		raydirx = all->plr_pos.dirx + planex * camerax;
		raydiry = all->plr_pos.diry + planey * camerax;

		double	side_distx;
		double	side_disty;

		double	delta_distx;
		double	delta_disty;

		if (raydiry == 0)
			delta_distx = 0;
		else
			delta_distx = ((raydirx == 0) ? 1 : fabs(1 / raydirx));
		
		if (raydirx == 0)
			delta_disty = 0;
		else
			delta_disty = ((raydiry == 0) ? 1 : fabs(1 / raydiry));

		double	ray_length;

		int		stepx;
		int		stepy;

		int		hit;

		hit = 0;

		int		side;

		if (raydirx < 0)
		{
			stepx = -1;
			side_distx = (all->plr_pos.x - all->dda.mapx) * delta_distx;
		}
		else
		{
			stepx = 1;
			side_distx = (all->dda.mapx + 1.0 - all->plr_pos.x) * delta_distx;
		}
		if (raydiry < 0)
		{
			stepy = -1;
			side_distx = (all->plr_pos.y - all->dda.mapy) * delta_disty;
		}
		else
		{
			stepy = 1;
			side_disty = (all->dda.mapy + 1.0 - all->plr_pos.y) * delta_disty;
		}

		// DDA
		while (hit == 0)
		{
			if (side_distx < side_disty)
			{
				side_distx += delta_distx;
			printf("side_distx = %f, delta_distx = %f\n", side_distx, delta_distx);
				all->dda.mapx += stepx;
				side = 0;
			}
			else
			{
				side_disty += delta_disty;
			printf("side_disty = %f, delta_disty = %f\n", side_disty, delta_disty);
				all->dda.mapy += stepy;
				side = 1;
			}
			printf("stepx%d, stepy%d\n", stepx, stepy);

			printf("mapx %d, mapy %d\n", all->dda.mapx, all->dda.mapy);
			printf("HERE\n");
			
			my_mlx_pixel_put(&all->window, all->plr_pos.x + side_distx,
						all->plr_pos.y + side_disty, 0x0000FF00);
			if (all->parsed.map[all->dda.mapy][all->dda.mapx] > 0)
			{
				printf("!!!!!!!!!!!!!!!!!!!!!\nHIT\n!!!!!!!!!!!!!!!!!!!!!!1\n");
				hit = 1;
			}
		}
		if (side == 0)
			ray_length = (all->dda.mapx - all->plr_pos.x + (1 - stepx) / 2) / raydirx;
		else
			ray_length = (all->dda.mapy - all->plr_pos.y + (1 - stepy) / 2) / raydiry;
		printf("ray_len = %f\n", ray_length);
	}
	return (0);
}
