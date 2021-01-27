/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cisis <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 14:39:35 by cisis             #+#    #+#             */
/*   Updated: 2020/11/01 18:52:25 by cisis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(const char *s, int c)
{
	unsigned char	chr;
	char			*str;

	chr = (unsigned char)c;
	str = (char*)s;
	while ((str) || (*str == '\0'))
	{
		if (*str == chr)
			return (str);
		else if (*str == '\0')
			break ;
		str++;
	}
	return (0);
}
