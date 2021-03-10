/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cisis <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 17:51:04 by cisis             #+#    #+#             */
/*   Updated: 2021/03/10 19:27:41 by cisis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int			close_window(t_all *all)
{
	free_parsed(&all->parsed);
	if (all->window.frame.img)
		mlx_destroy_image(all->window.mlx, all->window.frame.img);
	if (all->window.win)
		mlx_destroy_window(all->window.mlx, all->window.win);
	exit(0);
	return (0);
}
