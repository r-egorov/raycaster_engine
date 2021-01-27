/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cisis <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 20:38:53 by cisis             #+#    #+#             */
/*   Updated: 2021/01/27 15:41:11 by cisis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlen(const char *s)
{
	size_t			len;

	if (!s)
		return (0);
	len = 0;
	while (s[len])
		len += 1;
	return (len);
}

char		*ft_strjoin(char const *s1, char const *s2)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	len;
	char			*res;

	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	res = (char*)malloc((len + 1) * sizeof(char));
	if (!res)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		res[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		res[i + j] = s2[j];
		j++;
	}
	res[i + j] = '\0';
	return (res);
}

char		*ft_strchr(const char *s, int c)
{
	unsigned char	chr;
	char			*str;

	if (!s)
		return (0);
	chr = (unsigned char)c;
	str = (char*)s;
	while ((*str) || (*str == '\0'))
	{
		if (*str == chr)
			return (str);
		else if (*str == '\0')
			break ;
		str++;
	}
	return (0);
}

char		*ft_strdup(const char *s1)
{
	char			*res;
	size_t			len;
	size_t			i;

	len = ft_strlen(s1);
	if (!(res = (char*)malloc((len + 1) * sizeof(char))))
		return (NULL);
	i = 0;
	while (i < len)
	{
		res[i] = s1[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}
