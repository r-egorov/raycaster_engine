/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   infinite_hook.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cisis <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 16:02:12 by cisis             #+#    #+#             */
/*   Updated: 2021/02/10 11:13:13 by cisis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int			infinite_hook(t_all *all)
{
	calculate_plr_pos(all);
	render_next_frame(all);
	mlx_put_image_to_window(all->window.mlx,
			all->window.win, all->window.img, 0, 0);
	mlx_do_sync(all->window.mlx);
	return (0);
}
