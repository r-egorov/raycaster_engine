/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cisis <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 14:53:24 by cisis             #+#    #+#             */
/*   Updated: 2021/03/10 15:39:14 by cisis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	valid_char_in_map(char c)
{
	if ((c != '1') &&
		(c != '0') &&
		(c != '2') &&
		(c != ' ') &&
		(c != 'N') &&
		(c != 'S') &&
		(c != 'E') &&
		(c != 'W'))
	{
		g_errno = 18;
		return (0);
	}
	return (1);
}

static int	if_player_set(int x, int y, t_parsed *parsed)
{
	if (((parsed->map)[y][x] == 'N') ||
		((parsed->map)[y][x] == 'S') ||
		((parsed->map)[y][x] == 'E') ||
		((parsed->map)[y][x] == 'W'))
	{
		if (parsed->player_dir)
		{
			g_errno = 23;
			return (-1);
		}
		parsed->player_pos.x = x;
		parsed->player_pos.y = y;
		parsed->player_dir = (parsed->map)[y][x];
	}
	return (0);
}

static int	valid_map(t_parsed *parsed)
{
	int			x;
	int			y;
	char		**map;

	map = parsed->map;
	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if ((map[y][x] == '2') && (append_sprite(parsed, x, y) == -1))
				return (0);
			if ((!(valid_char_in_map(map[y][x]))) ||
				((map[y][x] == '0') && (!(valid_zero_map(parsed, x, y)))) ||
				((map[y][x] == ' ') && (!(valid_space_map(parsed, x, y)))) ||
				(if_player_set(x, y, parsed)))
				return (0);
			x++;
		}
		y++;
	}
	return (1);
}

void		validate_map(t_list **begin, t_parsed *parsed)
{
	t_list		*head;

	head = *begin;
	if ((make_map(&head, ft_lstsize(head), parsed)) == -1)
	{
		g_errno = 2;
		return ;
	}
	if (!(valid_map(parsed)))
		return ;
	*begin = head;
	make_sprite_arrays(parsed);
}
