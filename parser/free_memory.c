/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_memory.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cisis <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 15:51:37 by cisis             #+#    #+#             */
/*   Updated: 2021/02/16 11:15:20 by cisis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		free_strs(char **strs)
{
	size_t	i;

	if (strs)
	{
		i = 0;
		while (strs[i])
			free_str(strs[i++]);
		free_str(strs);
		strs = NULL;
	}
}

void		free_str(void *line)
{
	if (line)
		free(line);
	line = NULL;
}

void		free_parsed(t_parsed *parsed)
{
	char	**map;

	free_str(parsed->north_texture_path);
	free_str(parsed->south_texture_path);
	free_str(parsed->west_texture_path);
	free_str(parsed->east_texture_path);
	free_str(parsed->sprite_texture_path);
	free_str(parsed->floor_texture_path);
	free_str(parsed->ceiling_texture_path);
	map = parsed->map;
	free_strs(map);
}
