/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cisis <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 15:38:55 by cisis             #+#    #+#             */
/*   Updated: 2021/03/10 19:38:35 by cisis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static size_t	get_max_strlen(t_list **begin)
{
	t_list		*head;
	size_t		max_len;
	size_t		len;

	head = *begin;
	max_len = 0;
	while (head)
	{
		len = ft_strlen((char*)head->content);
		if (len > max_len)
			max_len = len;
		head = head->next;
	}
	return (max_len);
}

static int		map_malloc(char **map, int lst_size,
			t_list **begin, t_parsed *parsed)
{
	int			i;

	parsed->map_maxwidth = get_max_strlen(begin);
	i = 0;
	while (i < lst_size)
	{
		if (!(map[i++] = (char*)malloc(parsed->map_maxwidth
										* sizeof(char) + 1)))
			return (-1);
	}
	return (0);
}

static void		fill_str(char *dest, char *src, t_parsed *parsed)
{
	int		i;
	int		len;

	i = 0;
	len = ft_strlen(src);
	while (i < len)
	{
		dest[i] = src[i];
		i++;
	}
	while (i < (int)parsed->map_maxwidth)
		dest[i++] = ' ';
	dest[i] = '\0';
}

int				make_map(t_list **begin, t_parsed *parsed)
{
	char		**map;
	size_t		i;
	t_list		*head;

	head = *begin;
	if ((!(map = ft_calloc(parsed->map_height + 1, sizeof(char*)))) ||
		(map_malloc(map, parsed->map_height, begin, parsed) == -1))
		return (-1);
	i = 0;
	while (i < parsed->map_height)
	{
		if (*(char*)head->content == '\0')
			break ;
		fill_str(map[i++], (char*)head->content, parsed);
		head = head->next;
	}
	map[i] = NULL;
	parsed->map = map;
	*begin = head;
	return (0);
}
