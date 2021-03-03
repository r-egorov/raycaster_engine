/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_plr_pos.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cisis <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 15:47:51 by cisis             #+#    #+#             */
/*   Updated: 2021/02/17 10:24:51 by cisis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	move(t_all *all)
{
	if (all->keys.s == 1)
	{
		if (all->parsed.map[(int)(all->plr_pos.y)]\
				[(int)(all->plr_pos.x - all->plr_pos.dir.x * MOV_SPEED)] != '1')
			all->plr_pos.x -= all->plr_pos.dir.x * MOV_SPEED;
		if (all->parsed.map[(int)(all->plr_pos.y - all->plr_pos.dir.y
			* MOV_SPEED)][(int)(all->plr_pos.x)] != '1')
			all->plr_pos.y -= all->plr_pos.dir.y * MOV_SPEED;
	}
	if (all->keys.w == 1)
	{
		if (all->parsed.map[(int)(all->plr_pos.y)]\
				[(int)(all->plr_pos.x + all->plr_pos.dir.x * MOV_SPEED)] != '1')
			all->plr_pos.x += all->plr_pos.dir.x * MOV_SPEED;
		if (all->parsed.map[(int)(all->plr_pos.y + all->plr_pos.dir.y
			* MOV_SPEED)][(int)(all->plr_pos.x)] != '1')
			all->plr_pos.y += all->plr_pos.dir.y * MOV_SPEED;
	}
}

static void	strafe(t_all *all)
{
	if (all->keys.a == 1)
	{
		if (all->parsed.map[(int)(all->plr_pos.y)][(int)(all->plr_pos.x
							+ all->plr_pos.plane.x * MOV_SPEED)] != '1')
			all->plr_pos.x += all->plr_pos.plane.x * MOV_SPEED;
		if (all->parsed.map[(int)(all->plr_pos.y + all->plr_pos.plane.y
					* MOV_SPEED)][(int)(all->plr_pos.x)] != '1')
			all->plr_pos.y += all->plr_pos.plane.y * MOV_SPEED;
	}
	if (all->keys.d == 1)
	{
		if (all->parsed.map[(int)(all->plr_pos.y)][(int)(all->plr_pos.x
					- all->plr_pos.plane.x * MOV_SPEED)] != '1')
			all->plr_pos.x -= all->plr_pos.plane.x * MOV_SPEED;
		if (all->parsed.map[(int)(all->plr_pos.y - all->plr_pos.plane.y
					* MOV_SPEED)][(int)(all->plr_pos.x)] != '1')
			all->plr_pos.y -= all->plr_pos.plane.y * MOV_SPEED;
	}
}

static void	turn_left(t_all *all)
{
	double		olddir_x;
	double		oldplane_x;

	if (all->keys.left == 1)
	{
		olddir_x = all->plr_pos.dir.x;
		all->plr_pos.dir.x = all->plr_pos.dir.x * cos(-ROT_SPEED) -\
							all->plr_pos.dir.y * sin(-ROT_SPEED);
		all->plr_pos.dir.y = olddir_x * sin(-ROT_SPEED) +\
							all->plr_pos.dir.y * cos(-ROT_SPEED);
		oldplane_x = all->plr_pos.plane.x;
		all->plr_pos.plane.x = all->plr_pos.plane.x * cos(-ROT_SPEED) -\
							all->plr_pos.plane.y * sin(-ROT_SPEED);
		all->plr_pos.plane.y = oldplane_x * sin(-ROT_SPEED) +\
							all->plr_pos.plane.y * cos(-ROT_SPEED);
	}
}

static void	turn_right(t_all *all)
{
	double		olddir_x;
	double		oldplane_x;

	if (all->keys.right == 1)
	{
		olddir_x = all->plr_pos.dir.x;
		all->plr_pos.dir.x = all->plr_pos.dir.x * cos(ROT_SPEED) -\
							all->plr_pos.dir.y * sin(ROT_SPEED);
		all->plr_pos.dir.y = olddir_x * sin(ROT_SPEED) +\
							all->plr_pos.dir.y * cos(ROT_SPEED);
		oldplane_x = all->plr_pos.plane.x;
		all->plr_pos.plane.x = all->plr_pos.plane.x * cos(ROT_SPEED) -\
							all->plr_pos.plane.y * sin(ROT_SPEED);
		all->plr_pos.plane.y = oldplane_x * sin(ROT_SPEED) +\
							all->plr_pos.plane.y * cos(ROT_SPEED);
	}
}

int			calculate_plr_pos(t_all *all)
{
	move(all);
	strafe(all);
	turn_left(all);
	turn_right(all);
	return (0);
}
