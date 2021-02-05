/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cisis <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 13:38:09 by cisis             #+#    #+#             */
/*   Updated: 2021/02/05 14:37:00 by cisis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void            my_mlx_pixel_put(t_win *win, int x, int y, int color)
{
    char    *dst;

    dst = win->addr + (y * win->line_len + x * (win->bpp / 8));
    *(unsigned int*)dst = color;
}

void			draw_frame(t_all *all)
{
	draw_map(all);
	draw_player(all, RED);
}

int				render_next_frame(t_all *all)
{
	t_win		*window;
	t_parsed	*parsed;

	window = &(all->window);
	parsed = &(all->parsed);
	all->window.img = mlx_new_image(all->window.mlx, all->parsed.res_width, 
			all->parsed.res_height);
	all->window.addr = mlx_get_data_addr(all->window.img, &(all->window.bpp), 
			&(all->window.line_len), &(all->window.endian));
	draw_frame(all);
	mlx_put_image_to_window(all->window.mlx, all->window.win, all->window.img, 0, 0);
	mlx_do_sync(all->window.mlx);
	return (0);
}

