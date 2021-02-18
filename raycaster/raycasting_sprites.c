/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_sprites.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cisis <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 15:42:38 by cisis             #+#    #+#             */
/*   Updated: 2021/02/18 18:55:19 by cisis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	sort_sprites(int *sprite_order, double *sprite_distance,
		int n_sprites)
{
	int		i;
	int		j;

	i = n_sprites - 1;
	while (i > 0)
	{
		j = 0;
		while (j < i)
		{
			if (sprite_distance[j] < sprite_distance[j + 1])
			{
				double temp_d = sprite_distance[j + 1];
				sprite_distance[j + 1] = sprite_distance[j];
				sprite_distance[j] = temp_d;
				int temp_o = sprite_order[j + 1];
				sprite_order[j + 1] = sprite_order[j];
				sprite_order[j] = temp_o;
			}
			j++;
		}
		i--;
	}
}

int			cast_sprites(t_all *all)
{
	int		*sprite_order;
	double	*sprite_distance;
	
	sprite_order = all->parsed.sprite_order;
	sprite_distance = all->parsed.sprite_distance;


	int		i;

	i = 0;
	while (i < all->parsed.n_sprites)
	{
		sprite_order[i] = i;
		sprite_distance[i] = 
		((all->plr_pos.x - all->parsed.sprites[i].x)
		* (all->plr_pos.x - all->parsed.sprites[i].x) +
		(all->plr_pos.y - all->parsed.sprites[i].y)
		* (all->plr_pos.y - all->parsed.sprites[i].y));
		i++;
	}

	sort_sprites(sprite_order, sprite_distance, all->parsed.n_sprites);

	i = 0;

	while (i < all->parsed.n_sprites)
	{
		double sprite_x;
		double sprite_y;
	   
		sprite_x = all->parsed.sprites[sprite_order[i]].x - all->plr_pos.x;
		sprite_y = all->parsed.sprites[sprite_order[i]].y - all->plr_pos.y;

		double inv_det;

		inv_det = 1.0 / (all->plr_pos.plane.x * all->plr_pos.dir.y -
						all->plr_pos.dir.x * all->plr_pos.plane.y);

		double transform_x;
		double transform_y;
		
		transform_x = inv_det * (all->plr_pos.dir.y * sprite_x -
							all->plr_pos.dir.x * sprite_y);

		transform_y = inv_det * (-all->plr_pos.plane.y * sprite_x +
							all->plr_pos.plane.x * sprite_y);


		int	sprite_screen_x;
		
		sprite_screen_x = (int)((all->parsed.res_width / 2)
				* (1 + transform_x / transform_y));
	
		int	sprite_height;

		sprite_height = abs((int)(all->parsed.res_height / transform_y));

		int	draw_start_y;
		int	draw_end_y;

		draw_start_y = -sprite_height / 2 + all->parsed.res_height / 2;
		if (draw_start_y < 0)
			draw_start_y = 0;
		draw_end_y = sprite_height / 2 + all->parsed.res_height / 2;
		if (draw_end_y >= all->parsed.res_height)
			draw_end_y = all->parsed.res_height - 1;

		int sprite_width;
		sprite_width = abs((int)(all->parsed.res_height / transform_y));

		int	draw_start_x;
		int	draw_end_x;

		draw_start_x = -sprite_width / 2 + sprite_screen_x;
		if (draw_start_x < 0)
			draw_start_x = 0;
		draw_end_x = sprite_width / 2 + sprite_screen_x;
		if (draw_end_x >= all->parsed.res_width)
			draw_end_x = all->parsed.res_width - 1;

		int stripe;

		stripe = draw_start_x;

		unsigned int black;
		black = *(unsigned int*)(all->txtrs.sprite.addr);
		while (stripe < draw_end_x)
		{
			int	tex_x;

			tex_x = (int)(256 * (stripe - (-sprite_width / 2 + sprite_screen_x))
					* all->txtrs.sprite.width / sprite_width) / 256;
		
			if (transform_y > 0 && stripe > 0 &&
				stripe < all->parsed.res_width &&
				transform_y < all->parsed.zbuffer[stripe])
			{
				int		y;
				y = draw_start_y;
				while (y < draw_end_y)
				{
					int d;
					d = y * 256 - all->parsed.res_height * 128 + sprite_height * 128;
					int	tex_y;
					tex_y = ((d * all->txtrs.sprite.height) / sprite_height) / 256;
					unsigned int colour;
					colour = *(unsigned int*)(all->txtrs.sprite.addr
							+ (tex_y * all->txtrs.sprite.line_len
							+ tex_x * (all->txtrs.sprite.bpp / 8)));
					if (colour != black)
					{
						my_mlx_pixel_put(&(all->window.frame),
							all->parsed.res_width - stripe - 1, y, colour);
					}

					y++;
				}

			}
			stripe++;
		}
	i++;
	}
	return (0);
}
