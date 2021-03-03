/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_sprites.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cisis <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 15:42:38 by cisis             #+#    #+#             */
/*   Updated: 2021/02/25 15:52:18 by cisis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	sort_sprites(int *sprite_order, double *sprite_distance,
		int n_sprites)
{
	int		i;
	int		j;
	double	temp_d;
	double	temp_o;

	i = n_sprites - 1;
	while (i > 0)
	{
		j = 0;
		while (j < i)
		{
			if (sprite_distance[j] < sprite_distance[j + 1])
			{
				temp_d = sprite_distance[j + 1];
				sprite_distance[j + 1] = sprite_distance[j];
				sprite_distance[j] = temp_d;
				temp_o = sprite_order[j + 1];
				sprite_order[j + 1] = sprite_order[j];
				sprite_order[j] = temp_o;
			}
			j++;
		}
		i--;
	}
}

static void	fill_sprites_arrs(t_all *all)
{
	int		i;

	i = 0;
	while (i < all->parsed.n_sprites)
	{
		all->parsed.sprite_order[i] = i;
		all->parsed.sprite_distance[i] =
		((all->plr_pos.x - all->parsed.sprites[i].x)
		* (all->plr_pos.x - all->parsed.sprites[i].x) +
		(all->plr_pos.y - all->parsed.sprites[i].y)
		* (all->plr_pos.y - all->parsed.sprites[i].y));
		i++;
	}
}

static void	calc_sprite_values(t_all *all, t_dda_sprite *dda, int i)
{
	double sprite_x;
	double sprite_y;
	double inv_det;

	sprite_x = all->parsed.sprites[all->parsed.sprite_order[i]].x
		- all->plr_pos.x;
	sprite_y = all->parsed.sprites[all->parsed.sprite_order[i]].y
		- all->plr_pos.y;
	inv_det = 1.0 / (all->plr_pos.plane.x * all->plr_pos.dir.y -
					all->plr_pos.dir.x * all->plr_pos.plane.y);
	dda->transform_x = inv_det * (all->plr_pos.dir.y * sprite_x -
						all->plr_pos.dir.x * sprite_y);
	dda->transform_y = inv_det * (-all->plr_pos.plane.y * sprite_x +
						all->plr_pos.plane.x * sprite_y);
	dda->sprite_screen_x = (int)((all->parsed.res_width / 2)
			* (1 + dda->transform_x / dda->transform_y));
	dda->sprite_height = abs((int)(all->parsed.res_height / dda->transform_y));
	dda->sprite_width = abs((int)(all->parsed.res_height / dda->transform_y));
}

static void	calc_draw_coords(t_all *all, t_dda_sprite *dda)
{
	dda->draw_start_y = -dda->sprite_height / 2
		+ all->parsed.res_height / 2;
	if (dda->draw_start_y < 0)
		dda->draw_start_y = 0;
	dda->draw_end_y = dda->sprite_height / 2 + all->parsed.res_height / 2;
	if (dda->draw_end_y >= all->parsed.res_height)
		dda->draw_end_y = all->parsed.res_height - 1;
	dda->draw_start_x = -dda->sprite_width / 2 + dda->sprite_screen_x;
	if (dda->draw_start_x < 0)
		dda->draw_start_x = 0;
	dda->draw_end_x = dda->sprite_width / 2 + dda->sprite_screen_x;
	if (dda->draw_end_x >= all->parsed.res_width)
		dda->draw_end_x = all->parsed.res_width - 1;
}

int			cast_sprites(t_all *all)
{
	t_dda_sprite	*dda;
	int				i;

	dda = &all->dda_sprite;
	fill_sprites_arrs(all);
	sort_sprites(all->parsed.sprite_order, all->parsed.sprite_distance,
			all->parsed.n_sprites);
	i = 0;
	while (i < all->parsed.n_sprites)
	{
		calc_sprite_values(all, dda, i);
		calc_draw_coords(all, dda);
		draw_sprite(all, dda);
		i++;
	}
	return (0);
}
