/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_textures.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cisis <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 12:59:25 by cisis             #+#    #+#             */
/*   Updated: 2021/02/12 13:41:26 by cisis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void		get_img_and_path(t_img **texture, char **path,
								t_all *all, int mode)
{
	if (mode == 0)
	{
		*texture = &all->txtrs.north;
		*path = all->parsed.north_texture_path;
	}
	else if (mode == 1)
	{
		*texture = &all->txtrs.south;
		*path = all->parsed.south_texture_path;
	}
	else if (mode == 2)
	{
		*texture = &all->txtrs.west;
		*path = all->parsed.west_texture_path;
	}
	else if (mode == 3)
	{
		*texture = &all->txtrs.east;
		*path = all->parsed.east_texture_path;
	}
	else if (mode == 4)
	{
		*texture = &all->txtrs.sprite;
		*path = all->parsed.sprite_texture_path;
	}
}

static int		get_texture(t_all *all, int mode)
{
	t_img			*texture;
	char			*path;

	get_img_and_path(&texture, &path, all, mode);
	texture->img =  mlx_png_file_to_image(all->window.mlx,
			path,
			&texture->width, &texture->height);
	if (texture->img == NULL)
		return (-1);
	texture->addr = mlx_get_data_addr(texture->img,
			&(texture->bpp),
			&(texture->line_len), &(texture->endian));
	return (0);
}

int				get_textures(t_all *all)
{
	int		i;

	i = 0;
	while (i < 5)
	{
		if (get_texture(all, i) == -1)
			return (-1);
		i++;
	}
	return (0);
}
