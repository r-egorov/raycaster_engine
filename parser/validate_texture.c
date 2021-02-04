/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_texture.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cisis <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 11:23:30 by cisis             #+#    #+#             */
/*   Updated: 2021/02/02 13:39:50 by cisis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	set_path(char *path, int mode, t_parsed *parsed)
{
	if (mode == 1)
		parsed->north_texture_path = path;
	else if (mode == 2)
		parsed->south_texture_path = path;
	else if (mode == 3)
		parsed->west_texture_path = path;
	else if (mode == 4)
		parsed->east_texture_path = path;
	else if (mode == 5)
		parsed->sprite_texture_path = path;
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
	if ((fd_check = open(path, O_RDONLY)) == -1)
	{
		g_errno = 13;
		return ;
	}
	close(fd_check);
	set_path(path, mode, parsed);
}
