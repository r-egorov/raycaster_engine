/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_drawing.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cisis <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 16:30:57 by cisis             #+#    #+#             */
/*   Updated: 2021/02/26 11:27:23 by cisis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_img			get_texture(t_dda_wall *dda, t_all *all)
{
	t_img		texture;

	if (dda->side == 0)
	{
		if (dda->ray.x > 0)
			texture = all->txtrs.west;
		else
			texture = all->txtrs.east;
	}
	if (dda->side == 1)
	{
		if (dda->ray.y > 0)
			texture = all->txtrs.north;
		else
			texture = all->txtrs.south;
	}
	return (texture);
}

static void		calculate_line_params(t_dda_wall *dda, t_all *all,
		t_ver_line *line)
{
	line->height = (int)(all->parsed.res_height / dda->perp_wall_dist);
	line->draw_start = -line->height / 2 + all->parsed.res_height / 2;
	if (line->draw_start < 0)
		line->draw_start = 0;
	line->draw_finish = line->height / 2 + all->parsed.res_height / 2;
	if (line->draw_finish >= all->parsed.res_height)
		line->draw_finish = all->parsed.res_height - 1;
}

static int		calculate_texture_x(t_dda_wall *dda, t_all *all, t_img texture)
{
	double	wall_x;
	int		texture_x;

	if (dda->side == 0)
		wall_x = all->plr_pos.y + dda->perp_wall_dist * dda->ray.y;
	else
		wall_x = all->plr_pos.x + dda->perp_wall_dist * dda->ray.x;
	wall_x -= floor(wall_x);
	texture_x = (int)(wall_x * (double)(texture.width));
	if (dda->side == 0 && dda->ray.x > 0)
		texture_x = texture.width - texture_x - 1;
	if (dda->side == 1 && dda->ray.y < 0)
		texture_x = texture.width - texture_x - 1;
	return (texture_x);
}

static void		draw_texture_column(t_column *column, int x,
									t_img texture, t_all *all)
{
	int				y;
	unsigned int	colour;

	column->step = (double)texture.height / (double)column->line.height;
	column->texture_pos = (column->line.draw_start - all->parsed.res_height / 2
						+ column->line.height / 2) * column->step;
	y = column->line.draw_start;
	while (y < column->line.draw_finish)
	{
		column->texture_y = (int)column->texture_pos & (texture.height - 1);
		colour = *(unsigned int*)(texture.addr
				+ (column->texture_y * texture.line_len
				+ column->texture_x * (texture.bpp / 8)));
		my_mlx_pixel_put(&(all->window.frame),
				all->parsed.res_width - x - 1, y, colour);
		column->texture_pos += column->step;
		y++;
	}
}

void			draw_wall(int x, t_dda_wall *dda, t_all *all)
{
	t_img		texture;
	t_column	column;

	calculate_line_params(dda, all, &column.line);
	texture = get_texture(dda, all);
	column.texture_x = calculate_texture_x(dda, all, texture);
	draw_texture_column(&column, x, texture, all);
}
