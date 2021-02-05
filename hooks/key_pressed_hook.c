/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_pressed_hook.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cisis <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 15:03:49 by cisis             #+#    #+#             */
/*   Updated: 2021/02/05 15:48:20 by cisis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int			key_pressed_hook(int keycode, t_all *all)
{
	if (keycode == 13)
		all->keys.w = 1;
	else if (keycode == 0)
		all->keys.a = 1;
	else if (keycode == 1)
		all->keys.s = 1;
	else if (keycode == 2)
		all->keys.d = 1;
	return (0);
}

int			key_released_hook(int keycode, t_all *all)
{

	if (keycode == 13)
		all->keys.w = 0;
	else if (keycode == 0)
		all->keys.a = 0;
	else if (keycode == 1)
		all->keys.s = 0;
	else if (keycode == 2)
		all->keys.d = 0;
	return (0);
}
