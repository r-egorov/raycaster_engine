/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cisis <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 15:59:20 by cisis             #+#    #+#             */
/*   Updated: 2020/11/06 12:33:25 by cisis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_to_trim(char c, char const *set)
{
	while (*set)
	{
		if (c == *set++)
			return (1);
	}
	return (0);
}

char		*ft_strtrim(char const *s1, char const *set)
{
	char			*res;
	unsigned int	start;
	unsigned int	end;

	if (!set)
		return (ft_strdup(s1));
	if (!s1)
		return (NULL);
	if (ft_strlen(s1) == 0)
		end = 0;
	else
		end = ft_strlen(s1) - 1;
	start = 0;
	while ((s1[start]) && (start < end + 1) && (is_to_trim(s1[start], set)))
		start++;
	while ((end > 0) && (is_to_trim(s1[end], set)))
		end--;
	res = ft_substr(s1, start, end - start + 1);
	return (res);
}
