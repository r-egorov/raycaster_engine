/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cisis <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 17:53:40 by cisis             #+#    #+#             */
/*   Updated: 2021/02/05 14:33:25 by cisis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	looks_like_map(void *content)
{
	char			c;

	c = *((char *)content);
	if ((c == '1') || (c == ' '))
		return (1);
	return (0);
}

static int	looks_like_parameter(void *content)
{
	char			c;

	while (*(char*)content == ' ')
		content++;
	c = *((char *)content);
	if ((c == 'R') ||
		(c == 'N') ||
		(c == 'S') ||
		(c == 'W') ||
		(c == 'E') ||
		(c == 'S') ||
		(c == 'F') ||
		(c == 'C'))
		return (1);
	return (0);
}

static int	is_empty_str(void *content)
{
	char			c;

	c = *((char *)content);
	if (c == '\0')
		return (1);
	return (0);
}

int			validate_list(t_parsed *parsed, t_list *lst)
{
	t_list			*head;

	head = lst;
	while (head)
	{
		if (looks_like_parameter(head->content))
			validate_parameter(head->content, parsed);
		else if (looks_like_map(head->content))
			validate_map(&head, parsed);
		else if (is_empty_str(head->content))
		{
			head = head->next;
			continue ;
		}
		else
			g_errno = 1;
		if (g_errno || errno)
		{
			free_parsed(parsed);
			return (-1);
		}
		if (head)
			head = head->next;
	}
	return (0);
}
