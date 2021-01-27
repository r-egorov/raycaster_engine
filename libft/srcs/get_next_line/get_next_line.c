/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cisis <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 17:40:52 by cisis             #+#    #+#             */
/*   Updated: 2021/01/27 15:40:58 by cisis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_line(char **line, char **remainder)
{
	char	*nwln;
	char	*tmp;

	nwln = NULL;
	if ((nwln = ft_strchr(*remainder, '\n')))
	{
		*nwln = '\0';
		tmp = *remainder;
		*line = ft_strdup(*remainder);
		*remainder = ft_strdup(++nwln);
		free(tmp);
	}
	else
	{
		*line = ft_strdup(*remainder);
		free(*remainder);
		*remainder = NULL;
		return (0);
	}
	return (1);
}

static int	check_remainder(char **line, char **remainder, int bytes_read)
{
	if (bytes_read == -1)
	{
		if (*remainder != NULL)
		{
			free(*remainder);
			*remainder = NULL;
		}
		return (-1);
	}
	else if (bytes_read == 0 && !(*remainder))
	{
		*line = ft_strdup("");
		return (0);
	}
	return (get_line(line, remainder));
}

int			get_next_line(int fd, char **line)
{
	static char	*remainder[4096];
	char		*buf;
	char		*tmpbuf;
	int			bytes_read;

	if (fd < 0 || line == NULL || BUFFER_SIZE < 1 ||
		(!(buf = (char*)malloc((BUFFER_SIZE + 1) * sizeof(char)))))
		return (-1);
	while ((bytes_read = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[bytes_read] = '\0';
		if (!remainder[fd])
			remainder[fd] = ft_strdup(buf);
		else
		{
			tmpbuf = remainder[fd];
			remainder[fd] = ft_strjoin(remainder[fd], buf);
			free(tmpbuf);
		}
		if (ft_strchr(remainder[fd], '\n'))
			break ;
	}
	free(buf);
	buf = NULL;
	return (check_remainder(line, &remainder[fd], bytes_read));
}
