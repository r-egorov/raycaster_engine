/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   append_sprite.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cisis <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 16:32:09 by cisis             #+#    #+#             */
/*   Updated: 2021/02/18 13:59:35 by cisis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		make_sprite_arrays(t_parsed *parsed)
{
	int		*sprite_order;
	double	*sprite_distance;
	
	if (!(sprite_order = (int*)malloc(sizeof(int) * parsed->n_sprites)))
	{
		g_errno = 2;
		return ;
	}
	if (!(sprite_distance = (double*)malloc(sizeof(int) * parsed->n_sprites)))
	{
		g_errno = 2;
		return ;
	}

	parsed->sprite_order = sprite_order;
	parsed->sprite_distance = sprite_distance;
}

static void	copy_arr(t_fpoint *dest, t_fpoint *src, size_t src_size)
{
	size_t			i;

	i = 0;
	while (i < src_size)
	{
		dest[i] = src[i];
		i++;
	}
}

int			append_sprite(t_parsed *parsed, int x, int y)
{
	t_fpoint		sprite_position;
	t_fpoint		*new_array;
	t_fpoint		*old_array;

	old_array = parsed->sprites;
	parsed->n_sprites += 1;
	if (!(new_array = (t_fpoint*)malloc(sizeof(t_fpoint) * parsed->n_sprites)))
	{
		g_errno = 2;
		return (-1);
	}
	sprite_position.x = x + 0.5;
	sprite_position.y = y + 0.5;

	new_array[parsed->n_sprites - 1] = sprite_position;
	copy_arr(new_array, old_array, parsed->n_sprites - 1);

	parsed->sprites = new_array;
	free(old_array);

	return (0);
}
