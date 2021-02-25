/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_zero_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cisis <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 17:59:52 by cisis             #+#    #+#             */
/*   Updated: 2021/02/25 19:11:28 by cisis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	valid_surroudings(char c)
{
	if ((c == '0') ||
		(c == '1') ||
		(c == '2') ||
		(c == 'N') ||
		(c == 'S') ||
		(c == 'E') ||
		(c == 'W'))
		return (1);
	return (0);
}

int			valid_zero_map(t_parsed *parsed, int x, int y)
{
	int		line_len;
	int		i;
	int		j;

	line_len = ft_strlen((parsed->map)[y]);
	if ((y == 0) || (y == (int)parsed->map_height - 1) ||
		(x == 0) || (x == line_len))
		g_errno = 6;
	i = -1;
	while (i < 2)
	{
		j = -1;
		while (j < 2)
		{
			if ((!((i == 0) && (j == 0))) &&
				(!(valid_surroudings((parsed->map)[y + i][x + j]))))
				g_errno = 6;
			if (g_errno)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
