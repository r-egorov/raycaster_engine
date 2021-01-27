/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cisis <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 10:06:18 by cisis             #+#    #+#             */
/*   Updated: 2020/11/07 17:55:51 by cisis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	ft_numlen(int n)
{
	unsigned int	val;
	unsigned int	numlen;

	numlen = 0;
	if (n == 0)
		return (1);
	else if (n < 0)
	{
		numlen += 1;
		val = n * -1;
	}
	else
		val = n;
	while (val > 0)
	{
		val = val / 10;
		numlen += 1;
	}
	return (numlen);
}

char				*ft_itoa(int n)
{
	char			*res;
	char			*last;
	unsigned int	val;
	unsigned int	numlen;

	if (n == 0)
		return (ft_strdup("0"));
	numlen = ft_numlen(n);
	if (!(res = (char*)malloc((numlen + 1) * sizeof(char))))
		return (NULL);
	else if (n < 0)
	{
		*res = '-';
		val = n * -1;
	}
	else
		val = n;
	last = res + (numlen);
	*last = '\0';
	while (val > 0)
	{
		*--last = (char)((val % 10) + '0');
		val = val / 10;
	}
	return (res);
}
