/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cisis <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 12:07:14 by cisis             #+#    #+#             */
/*   Updated: 2020/11/03 12:29:54 by cisis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	slen;
	char			*res;

	if (!(s))
		return (NULL);
	slen = ft_strlen(s);
	if (start >= slen)
		len = 0;
	res = (char*)malloc((len + 1) * sizeof(char));
	if (!(res))
		return (NULL);
	res = (char*)ft_memcpy(res, s + start, len);
	res[len] = '\0';
	return (res);
}
