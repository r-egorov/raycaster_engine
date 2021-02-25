/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cisis <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 17:53:40 by cisis             #+#    #+#             */
/*   Updated: 2021/02/25 19:09:57 by cisis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	check_for_remainder(t_list *head)
{
	while (head)
	{
		if (*((char*)(head->content)) != '\0')
		{
			g_errno = 4;
			return ;
		}
		head = head->next;
	}
}

static int	looks_like_map(void *content)
{
	char			c;

	c = *((char*)content);
	if ((c == '1') || (c == ' '))
		return (1);
	return (0);
}

int			validate_list(t_parsed *parsed, t_list *lst)
{
	t_list			*head;

	head = lst;
	validate_parameters(&head, parsed);
	if (!g_errno)
	{
		while (*((char*)(head->content)) == '\0')
			head = head->next;
		if (looks_like_map(head->content))
			validate_map(&head, parsed);
		else
			g_errno = 5;
		if (!g_errno)
			check_for_remainder(head);
	}
	if (g_errno || errno)
	{
		free_parsed(parsed);
		return (-1);
	}
	return (0);
}
