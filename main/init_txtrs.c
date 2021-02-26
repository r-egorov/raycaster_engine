/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_txtrs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cisis <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/26 11:39:37 by cisis             #+#    #+#             */
/*   Updated: 2021/02/26 11:40:31 by cisis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	init_img(t_img *img)
{
	img->img = NULL;
	img->addr = NULL;
	img->bpp = 0;
	img->line_len = 0;
	img->endian = 0;
	img->height = 0;
	img->width = 0;
}

void		init_txtrs(t_txtrs *txtrs)
{
	init_img(&(txtrs->north));
	init_img(&(txtrs->south));
	init_img(&(txtrs->west));
	init_img(&(txtrs->east));
	init_img(&(txtrs->sprite));
	init_img(&(txtrs->floor));
	init_img(&(txtrs->ceiling));
}
