/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_sprites_drawing.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cisis <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 15:51:07 by cisis             #+#    #+#             */
/*   Updated: 2021/02/25 16:00:49 by cisis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	draw_line(t_all *all, t_dda_sprite *dda, int x, int texture_x)
{
	int				y;
	int				d;
	int				texture_y;
	unsigned int	colour;

	y = dda->draw_start_y;
	while (y < dda->draw_end_y)
	{
		d = y * 256 - all->parsed.res_height * 128 + dda->sprite_height * 128;
		texture_y = ((d * all->txtrs.sprite.height) / dda->sprite_height) / 256;
		colour = *(unsigned int*)(all->txtrs.sprite.addr
				+ (texture_y * all->txtrs.sprite.line_len
				+ texture_x * (all->txtrs.sprite.bpp / 8)));
		if (colour != 0)
		{
			my_mlx_pixel_put(&(all->window.frame),
				all->parsed.res_width - x - 1, y, colour);
		}
		y++;
	}
}

static void	draw_column(t_all *all, t_dda_sprite *dda, int x)
{
	int				texture_x;

	texture_x = (int)((x - (-dda->sprite_width / 2 + dda->sprite_screen_x))
			* all->txtrs.sprite.width / dda->sprite_width);
	if (dda->transform_y > 0 && x > 0 && x < all->parsed.res_width &&
		dda->transform_y < all->parsed.zbuffer[x])
		draw_line(all, dda, x, texture_x);
}

void		draw_sprite(t_all *all, t_dda_sprite *dda)
{
	int x;

	x = dda->draw_start_x;
	while (x < dda->draw_end_x)
	{
		draw_column(all, dda, x);
		x++;
	}
}
