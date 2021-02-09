/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_draw.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cisis <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 13:10:35 by cisis             #+#    #+#             */
/*   Updated: 2021/02/09 11:25:41 by cisis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		draw_player(t_all *all, int colour)
{
	t_point		topleft;
	int			i;
	int			j;

	topleft.x = all->plr_pos.x * SCALE + SCALE/2 - 2;
	topleft.y = all->plr_pos.y * SCALE + SCALE/2 - 2;
	i = 0;
	while (i < 5)
	{
		j = 0;
		while (j < 5)
		{
			my_mlx_pixel_put(&(all->window), topleft.x + j, topleft.y + i,
							colour);
			j++;
		}
		i++;
	}
}
