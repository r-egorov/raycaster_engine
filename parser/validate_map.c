/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cisis <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 14:53:24 by cisis             #+#    #+#             */
/*   Updated: 2021/02/02 18:30:32 by cisis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static char	**make_map(t_list *head, int lst_size)
{
	char		**map;
	size_t		i;

	if (!(map = ft_calloc(lst_size + 1, sizeof(char*))))
		return (NULL);
	i = 0;
	while (head)
	{
		if (!(map[i++] = ft_strdup(head->content)))
			return (NULL);
		head = head->next;
	}
	map[i] = NULL;
	return (map);
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
	char		**map;

	head = *begin;	
	if (!(map = make_map(head, ft_lstsize(head))))
	{
		g_errno = 2;
		return ;
	}
	if (!(valid_map(map)))
	{
		free_strs(map);
		return ;
	}
	parsed->map = map;
	*begin = NULL;
}
