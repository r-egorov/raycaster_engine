/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cisis <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 13:30:09 by cisis             #+#    #+#             */
/*   Updated: 2020/11/06 13:50:13 by cisis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newlst;
	t_list	*newelem;

	if (lst)
	{
		newlst = ft_lstnew(f(lst->content));
		lst = lst->next;
		while (lst)
		{
			newelem = ft_lstnew(f(lst->content));
			if (!newelem)
			{
				ft_lstclear(&newlst, del);
				return (NULL);
			}
			ft_lstadd_back(&newlst, newelem);
			lst = lst->next;
		}
		return (newlst);
	}
	return (NULL);
}
