/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cisis <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 17:45:35 by cisis             #+#    #+#             */
/*   Updated: 2020/12/08 14:33:52 by cisis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	fill_the_tab(char **tab, int *remainders, const char *base,
		int res_len)
{
	int					i;
	char				*res;

	res = *tab;
	i = 0;
	while (--res_len >= 0)
	{
		res[i] = base[remainders[res_len]];
		i++;
	}
	res[i] = '\0';
}

char		*ft_lutoa_base(unsigned long nbr, const char *base)
{
	int					base_len;
	int					remainders[64];
	int					i;
	char				*res;

	if (nbr == 0)
		return (ft_strdup("0"));
	base_len = ft_strlen(base);
	i = 0;
	while (nbr > 0)
	{
		remainders[i] = nbr % base_len;
		nbr = nbr / base_len;
		i++;
	}
	if (!(res = (char*)malloc((i + 1) & sizeof(char))))
		return (NULL);
	fill_the_tab(&res, remainders, base, i);
	return (res);
}
