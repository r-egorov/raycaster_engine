/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cisis <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 15:47:50 by cisis             #+#    #+#             */
/*   Updated: 2021/01/27 16:22:26 by cisis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int			parse_file(char *filepath)
{
	int		fd;
	int		gnl;
	char	*line;

	if ((fd = open(filepath, O_RDONLY)) == -1)
		return (process_error());
	
	gnl = 1;
	while (gnl == 1)
	{
		gnl = get_next_line(fd, &line);
		printf("%s\n", line);
		free(line);
	}
	return (0);
}
