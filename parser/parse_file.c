/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cisis <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 15:47:50 by cisis             #+#    #+#             */
/*   Updated: 2021/02/05 17:15:44 by cisis            ###   ########.fr       */
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
	return (0);
}

int				parse_file(char *filepath, t_parsed *parsed)
{
	int			fd;
	t_list		*head;

	head = NULL;
	if (((fd = open(filepath, O_RDONLY)) == -1) ||
		(init_list(fd, &head) == -1) ||
		(validate_list(parsed, head)) == -1)
		return (process_error());
	ft_lstclear(&head, free_str);
	return (0);
}
