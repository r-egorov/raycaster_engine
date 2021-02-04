/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cisis <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 14:53:24 by cisis             #+#    #+#             */
/*   Updated: 2021/02/04 13:06:38 by cisis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	make_map(t_list *head, int lst_size, t_parsed *parsed)
{
	char		**map;
	size_t		i;

	if (!(map = ft_calloc(lst_size + 1, sizeof(char*))))
		return (-1);
	i = 0;
	while (head)
	{
		if (*(char*)head->content == '\0')
			break ;
		if (!(map[i++] = ft_strdup(head->content)))
			return (-1);
		head = head->next;
	}
	map[i] = NULL;
	parsed->map = map;
	parsed->map_height = i;
	return (0);
}

static int	valid_map(char **map)
{
	char **dummy;
	dummy = map;
/*	size_t		x;
	size_t		y;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (!(valid_char_in_map(map[y][x])))
				g_errno = 18;
			else if ((map[y][x] == '0') && (!(valid_zero_in_map(map, x, y))))
				g_errno = 19;
			else if ((map[y][x] == ' ') && (!(valid_space_in_map(map, x, y))))
				g_errno = 20;
			if (g_errno)
				return (0);
			x++;
		}
		y++;
	}*/
	return (1);
}

void		validate_map(t_list **begin, t_parsed *parsed)
{
	t_list		*head;

	head = *begin;	
	if ((make_map(head, ft_lstsize(head), parsed)) == -1)
	{
		g_errno = 2;
		return ;
	}
	if (!(valid_map(parsed->map)))
	{
		free_strs(parsed->map);
		return ;
	}
	*begin = NULL;
}
