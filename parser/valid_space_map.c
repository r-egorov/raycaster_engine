/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_zero_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cisis <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 17:59:52 by cisis             #+#    #+#             */
/*   Updated: 2021/02/25 19:13:46 by cisis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	valid_surroudings(char c)
{
	if ((c == '1') ||
		(c == ' '))
		return (1);
	return (0);
}

int			valid_space_map(t_parsed *parsed, int x, int y)
{
	int		line_len;
	int		i;
	int		j;

	line_len = ft_strlen((parsed->map)[y]);
	i = -1;
	while (i < 2)
	{
		j = -1;
		while (j < 2)
		{
			if ((x + j > 0 && x + j < line_len) &&
				(y + i > 0 && y + i < (int)parsed->map_height))
			{
				if ((!((i == 0) && (j == 0))) &&
					(!(valid_surroudings((parsed->map)[y + i][x + j]))))
					g_errno = 6;
				if (g_errno)
					return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}
