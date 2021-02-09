/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_plr_pos.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cisis <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 15:47:51 by cisis             #+#    #+#             */
/*   Updated: 2021/02/09 18:02:33 by cisis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int			calculate_plr_pos(t_all *all)
{
	t_vector	strafe;

	strafe.x = all->plr_pos.dir.y;
	strafe.y = all->plr_pos.dir.x * -1;

	if (all->keys.s == 1)
	{
		if (all->parsed.map[(int)(all->plr_pos.y)]\
				[(int)(all->plr_pos.x - all->plr_pos.dir.x * 0.1)] != '1')
			all->plr_pos.x -= all->plr_pos.dir.x * 0.1;
		if (all->parsed.map[(int)(all->plr_pos.y - all->plr_pos.dir.y * 0.1)]\
				[(int)(all->plr_pos.x)] != '1')
			all->plr_pos.y -= all->plr_pos.dir.y * 0.1;
	}
	if (all->keys.w == 1)
	{
		if (all->parsed.map[(int)(all->plr_pos.y)]\
				[(int)(all->plr_pos.x + all->plr_pos.dir.x * 0.1)] != '1')
			all->plr_pos.x += all->plr_pos.dir.x * 0.1;
		if (all->parsed.map[(int)(all->plr_pos.y + all->plr_pos.dir.y * 0.1)]\
				[(int)(all->plr_pos.x)] != '1')
			all->plr_pos.y += all->plr_pos.dir.y * 0.1;
	}
	if (all->keys.a == 1)
	{
		if (all->parsed.map[(int)(all->plr_pos.y)]\
				[(int)(all->plr_pos.x + strafe.x * 0.1)] != '1')
			all->plr_pos.x += strafe.x * 0.1;
		if (all->parsed.map[(int)(all->plr_pos.y + strafe.y * 0.1)]\
				[(int)(all->plr_pos.x)] != '1')
			all->plr_pos.y += strafe.y * 0.1;
	}
	if (all->keys.d == 1)
	{
		if (all->parsed.map[(int)(all->plr_pos.y)]\
				[(int)(all->plr_pos.x - strafe.x * 0.1)] != '1')
			all->plr_pos.x -= strafe.x * 0.1;
		if (all->parsed.map[(int)(all->plr_pos.y - strafe.y * 0.1)]\
				[(int)(all->plr_pos.x)] != '1')
			all->plr_pos.y -= strafe.y * 0.1;
	}
	if (all->keys.left == 1)
	{
		double		olddir_x;
		olddir_x = all->plr_pos.dir.x;
		all->plr_pos.dir.x = all->plr_pos.dir.x * cos(-0.1) -\
							 all->plr_pos.dir.y * sin(-0.1);
		all->plr_pos.dir.y = olddir_x * sin(-0.1) +\
							 all->plr_pos.dir.y * cos(-0.1);

		double		oldplane_x;
		oldplane_x = all->plr_pos.plane.x;
		all->plr_pos.plane.x = all->plr_pos.plane.x * cos(-0.1) -\
							 all->plr_pos.plane.y * sin(-0.1);
		all->plr_pos.plane.y = oldplane_x * sin(-0.1) +\
							 all->plr_pos.plane.y * cos(-0.1);

	}
	if (all->keys.right == 1)
	{
		double		olddir_x;
		olddir_x = all->plr_pos.dir.x;
		all->plr_pos.dir.x = all->plr_pos.dir.x * cos(0.1) -\
							 all->plr_pos.dir.y * sin(0.1);
		all->plr_pos.dir.y = olddir_x * sin(0.1) +\
							 all->plr_pos.dir.y * cos(0.1);

		double		oldplane_x;
		oldplane_x = all->plr_pos.plane.x;
		all->plr_pos.plane.x = all->plr_pos.plane.x * cos(0.1) -\
							 all->plr_pos.plane.y * sin(0.1);
		all->plr_pos.plane.y = oldplane_x * sin(0.1) +\
							 all->plr_pos.plane.y * cos(0.1);

	}
	//printf("plrx = %f\nplry = %f\n", all->plr_pos.x, all->plr_pos.y); //PRINTF
	//printf("plrx = %d\nplry = %d\n", (int)all->plr_pos.x, (int)all->plr_pos.y); //PRINTF
	return (0);
}
