/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cisis <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 17:58:54 by cisis             #+#    #+#             */
/*   Updated: 2020/10/30 18:19:51 by cisis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t		d_i;
	size_t		s_i;

	d_i = 0;
	s_i = 0;
	while (dst[d_i] && d_i < dstsize)
		d_i++;
	while (src[s_i] && ((d_i + s_i + 1) < dstsize))
	{
		dst[d_i + s_i] = src[s_i];
		s_i++;
	}
	if (d_i != dstsize)
		dst[d_i + s_i] = '\0';
	return (d_i + ft_strlen(src));
}
