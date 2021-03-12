/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cisis <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 15:47:50 by cisis             #+#    #+#             */
/*   Updated: 2021/03/12 12:57:21 by cisis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int		list_append(t_list **head, char *line)
{
	char		*line_copy;

	if (!(line_copy = ft_strdup(line)))
		return (-1);
	ft_lstadd_back(head, ft_lstnew(line_copy));
	return (0);
}

static int		init_list(int fd, t_list **head)
{
	int			gnl;
	char		*line;

	gnl = 1;
	while (gnl == 1)
	{
		if ((gnl = get_next_line(fd, &line)) == -1)
		{
			free_str(line);
			ft_lstclear(head, free_str);
			return (-1);
		}
		list_append(head, line);
		free_str(line);
	}
	close(fd);
	return (0);
}

static int		is_cub(char *filepath)
{
	size_t		last;

	last = ft_strlen(filepath) - 1;
	if (filepath[last] == 'b' &&
		filepath[last - 1] == 'u' &&
		filepath[last - 2] == 'c' &&
		filepath[last - 3] == '.')
		return (1);
	g_errno = 1;
	return (0);
}

int				parse_file(char *filepath, t_parsed *parsed)
{
	int			fd;
	int			res;
	t_list		*head;

	res = 0;
	fd = 0;
	head = NULL;
	if ((!(is_cub(filepath))) ||
		((fd = open(filepath, O_RDONLY)) == -1) ||
		(init_list(fd, &head) == -1) ||
		(validate_list(parsed, head)) == -1)
		res = -1;
	ft_lstclear(&head, free_str);
	if (fd > 0)
		close(fd);
	if (res == -1)
		return (process_error());
	return (res);
}
