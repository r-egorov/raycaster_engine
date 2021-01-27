/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cisis <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 00:56:02 by cisis             #+#    #+#             */
/*   Updated: 2020/11/02 12:34:57 by cisis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t		i;
	size_t		k;

	i = 0;
	if (!little[0])
		return ((char*)&big[0]);
	while (big[i] && (i < len))
	{
		k = 0;
		while ((big[i + k] == little[k]) && ((i + k) < len) && little[k])
			k++;
		if (little[k] == '\0')
			return ((char*)&big[i]);
		i++;
	}
	return (NULL);
}
