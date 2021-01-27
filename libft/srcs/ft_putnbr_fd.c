/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cisis <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 11:07:09 by cisis             #+#    #+#             */
/*   Updated: 2020/11/05 11:12:18 by cisis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int val;

	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		val = n * -1;
	}
	else
		val = n;
	if (val <= 9)
		ft_putchar_fd(val + '0', fd);
	else
	{
		ft_putnbr_fd(val / 10, fd);
		ft_putnbr_fd(val % 10, fd);
	}
}
