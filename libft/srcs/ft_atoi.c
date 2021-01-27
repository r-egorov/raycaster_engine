/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cisis <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 18:27:12 by cisis             #+#    #+#             */
/*   Updated: 2020/12/01 15:18:05 by cisis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	ft_isspace(char c)
{
	if ((c == ' ') ||
	(c == '\f') ||
	(c == '\n') ||
	(c == '\r') ||
	(c == '\t') ||
	(c == '\v'))
		return (1);
	return (0);
}

int			ft_atoi(const char *nptr)
{
	int				i;
	long			sign;
	unsigned long	res;

	i = 0;
	sign = 1;
	res = 0;
	while (ft_isspace((char)nptr[i]))
		i++;
	if ((nptr[i] == '-') || (nptr[i] == '+'))
	{
		if (nptr[i] == '-')
			sign *= -1;
		i++;
	}
	while ((nptr[i] >= 48) && (nptr[i] <= 57))
	{
		res = 10 * res + ((unsigned char)nptr[i] - '0');
		i++;
	}
	return ((int)(res * sign));
}
