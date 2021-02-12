/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cisis <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 13:38:09 by cisis             #+#    #+#             */
/*   Updated: 2021/02/12 17:54:22 by cisis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void			my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_len + x * (img->bpp / 8));
	*(unsigned int*)dst = color;
}

void			draw_frame(t_all *all)
{
	cast_rays(all);
}

void			draw_ceiling(t_all *all, int x, t_ver_line line,
							unsigned int colour)
{
	int		y;

	y = 0;
	while (y < line.draw_start)
	{
		my_mlx_pixel_put(&(all->window.frame), all->parsed.res_width - x - 1, y,
						colour);
		y++;
	}
}

void			draw_floor(t_all *all, int x, t_ver_line line,
							unsigned int colour)
{
	int		y;

	y = line.draw_finish;
	while (y < all->parsed.res_height - 1)
	{
		my_mlx_pixel_put(&(all->window.frame), all->parsed.res_width - x - 1, y,
						colour);
		y++;
	}
}

int				render_next_frame(t_all *all)
{
	t_win		*window;
	t_parsed	*parsed;

	window = &(all->window);
	parsed = &(all->parsed);
	if (all->window.frame.img)
		mlx_destroy_image(all->window.mlx, all->window.frame.img);
	all->window.frame.img = mlx_new_image(all->window.mlx,
										all->parsed.res_width,
										all->parsed.res_height);
	all->window.frame.addr = mlx_get_data_addr(all->window.frame.img,
										&(all->window.frame.bpp),
										&(all->window.frame.line_len),
										&(all->window.frame.endian));
	draw_frame(all);
	return (0);
}
