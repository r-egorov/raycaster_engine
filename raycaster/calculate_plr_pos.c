/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_plr_pos.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cisis <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 15:47:51 by cisis             #+#    #+#             */
/*   Updated: 2021/02/09 11:28:42 by cisis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int			calculate_plr_pos(t_all *all)
{
	if (all->keys.s == 1)
		all->plr_pos.y += 0.1;
	if (all->keys.w == 1)
		all->plr_pos.y -= 0.1;
	if (all->keys.a == 1)
		all->plr_pos.x -= 0.1;
	if (all->keys.d == 1)
		all->plr_pos.x += 0.1;
	all->plr_pos.dirx = -1;
	all->plr_pos.diry = 0;
	return (0);
}
