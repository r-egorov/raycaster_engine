/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_texture.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cisis <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 11:23:30 by cisis             #+#    #+#             */
/*   Updated: 2021/02/25 18:35:24 by cisis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	set_floor_ceiling(char *path, int mode, t_parsed *parsed)
{
	if ((mode == 6) && (parsed->floor_texture_path || parsed->floor_colour))
		g_errno = 30;
	else if (mode == 6)
		parsed->floor_texture_path = path;
	else if ((mode == 7) &&
			(parsed->ceiling_texture_path || parsed->ceiling_colour))
		g_errno = 31;
	else if (mode== 7)
		parsed->ceiling_texture_path = path;
}

static void	set_path(char *path, int mode, t_parsed *parsed)
{
	if ((mode == 1) && (parsed->north_texture_path))
		g_errno = 25;
	else if (mode == 1)
		parsed->north_texture_path = path;
	else if ((mode == 2) && (parsed->south_texture_path))
		g_errno = 26;
	else if (mode == 2)
		parsed->south_texture_path = path;
	else if ((mode == 3) && (parsed->west_texture_path))
		g_errno = 27;
	else if (mode == 3)
		parsed->west_texture_path = path;
	else if ((mode == 4) && (parsed->east_texture_path))
		g_errno = 28;
	else if (mode == 4)
		parsed->east_texture_path = path;
	else if ((mode == 5) && (parsed->sprite_texture_path))
		g_errno = 29;
	else if (mode == 5)
		parsed->sprite_texture_path = path;
	else
		set_floor_ceiling(path, mode, parsed);
}

static int	is_png(char *path)
{
	int		last_char;

	last_char = ft_strlen(path) - 1;
	if ((path[last_char] == 'g') &&
		(path[last_char - 1] == 'n') &&
		(path[last_char - 2] == 'p') &&
		(path[last_char - 3] == '.'))
		return (1);
	return (0);
}

void		validate_texture(char **parameters, t_parsed *parsed, int mode)
{
	char	*path;
	int		fd_check;

	if (!(valid_number_params(parameters, 2)))
	{
		g_errno = 14;
		return ;
	}
	if (!(path = ft_strdup(parameters[1])))
	{
		g_errno = 2;
		return ;
	}
	if (!(is_png(path)))
	{
		g_errno = 21;
		return ;
	}
	if ((fd_check = open(path, O_RDONLY)) == -1)
	{
		g_errno = 13;
		return ;
	}
	close(fd_check);
	set_path(path, mode, parsed);
}
