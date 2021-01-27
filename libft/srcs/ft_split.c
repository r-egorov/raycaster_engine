/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cisis <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 12:35:50 by cisis             #+#    #+#             */
/*   Updated: 2020/11/07 13:59:43 by cisis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	count_words(char const *s, char c)
{
	unsigned int	i;
	unsigned int	word_count;

	i = 0;
	word_count = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i] && s[i] != c)
		{
			word_count += 1;
			while (s[i] && s[i] != c)
				i++;
		}
	}
	return (word_count);
}

static char			*get_word(char const *s, char c)
{
	unsigned int	len;
	unsigned int	i;
	char			*word;

	len = 0;
	i = 0;
	while (s[len] && s[len] != c)
		len += 1;
	word = (char*)malloc((len + 1) * sizeof(char));
	while (*s && *s != c)
	{
		word[i] = *s++;
		i++;
	}
	word[i] = '\0';
	return (word);
}

static	char		**free_strstab(char **strstab, unsigned int i)
{
	unsigned int	j;

	j = 0;
	while (j < i)
	{
		free(strstab[j]);
		j++;
	}
	free(strstab);
	return (NULL);
}

char				**ft_split(char const *s, char c)
{
	char			**res;
	unsigned int	word_count;
	unsigned int	i;

	if (!s)
		return (NULL);
	i = 0;
	word_count = count_words(s, c);
	if (!(res = (char**)malloc((word_count + 1) * sizeof(char*))))
		return (NULL);
	while (i < word_count)
	{
		while (*s && *s == c)
			s++;
		if (*s && *s != c)
		{
			if (!(res[i] = get_word(s, c)))
				return (free_strstab(res, i));
			i++;
			while (*s && *s != c)
				s++;
		}
	}
	res[i] = NULL;
	return (res);
}
