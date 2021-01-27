/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cisis <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 13:17:54 by cisis             #+#    #+#             */
/*   Updated: 2020/11/06 13:23:38 by cisis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list		*head;
	t_list		*tmp;

	head = *lst;
	while (head)
	{
		tmp = head;
		head = head->next;
		del(tmp->content);
		free(tmp);
	}
	*lst = NULL;
}
