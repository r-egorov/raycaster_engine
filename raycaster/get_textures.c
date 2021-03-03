/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_textures.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cisis <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 12:59:25 by cisis             #+#    #+#             */
/*   Updated: 2021/03/03 12:49:47 by cisis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void		get_wall_texture(t_img **texture, char **path,
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

static void		get_floor_ceiling_texture(t_img **texture, char **path,
										t_all *all, int mode)
{
	if (mode == 5)
	{
		*texture = &all->txtrs.floor;
		*path = all->parsed.floor_texture_path;
	}
	else if (mode == 6)
	{
		*texture = &all->txtrs.ceiling;
		*path = all->parsed.ceiling_texture_path;
	}
}

static void		get_img_and_path(t_img **texture, char **path,
								t_all *all, int mode)
{
	if (mode < 5)
		get_wall_texture(texture, path, all, mode);
	else
		get_floor_ceiling_texture(texture, path, all, mode);
}

static int		get_texture(t_all *all, int mode)
{
	t_img			*texture;
	char			*path;

	get_img_and_path(&texture, &path, all, mode);
	if (path)
	{
		texture->img = mlx_xpm_file_to_image(all->window.mlx,
				path,
				&texture->width, &texture->height);
		if (texture->img == NULL)
			return (-1);
		texture->addr = mlx_get_data_addr(texture->img,
				&(texture->bpp),
				&(texture->line_len), &(texture->endian));
	}
	return (0);
}

int				get_textures(t_all *all)
{
	int		i;

	i = 0;
	while (i < 7)
	{
		if (get_texture(all, i) == -1)
			return (-1);
		i++;
	}
	return (0);
}
