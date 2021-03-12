/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_screenshot.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cisis <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/26 15:11:29 by cisis             #+#    #+#             */
/*   Updated: 2021/03/12 12:59:43 by cisis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	int_to_char(unsigned char *dataset, int value)
{
	dataset[0] = (unsigned char)(value);
	dataset[1] = (unsigned char)(value >> 8);
	dataset[2] = (unsigned char)(value >> 16);
	dataset[3] = (unsigned char)(value >> 24);
}

static int	make_header(int fd, int bmpsize, t_all *all)
{
	int				i;
	unsigned char	header[54];

	i = 0;
	while (i < 54)
		header[i++] = 0;
	header[0] = 'B';
	header[1] = 'M';
	int_to_char(header + 2, bmpsize);
	header[10] = 54;
	header[14] = 40;
	int_to_char(header + 18, all->parsed.res_width);
	int_to_char(header + 22, all->parsed.res_height);
	header[26] = 1;
	header[28] = 32;
	if (write(fd, header, 54) < 0)
		return (-1);
	return (0);
}

static int	get_colour(t_all *all, int x, int y)
{
	unsigned int	colour;
	t_img			*frame;

	frame = &(all->window.frame);
	colour = *(unsigned int*)(frame->addr + y * frame->line_len +
			x * (frame->bpp / 8));
	return (colour);
}

static int	make_bmp(int fd, t_all *all)
{
	int					y;
	int					x;
	unsigned int		colour;

	y = all->parsed.res_height - 1;
	while (y >= 0)
	{
		x = 0;
		while (x < all->parsed.res_width)
		{
			colour = get_colour(all, x, y);
			if (write(fd, &colour, 4) < 0)
				return (-1);
			x++;
		}
		y--;
	}
	return (0);
}

int			make_screenshot(t_all *all)
{
	int		bmpsize;
	int		fd;

	bmpsize = 54 + (4 * all->parsed.res_width * all->parsed.res_height);
	if (!((fd = open("screenshot.bmp", O_WRONLY | O_CREAT, 0666)) >= 0
		&& (make_header(fd, bmpsize, all) != -1)
		&& (make_bmp(fd, all) != -1)))
	{
		process_error();
		return (-1);
	}
	close(fd);
	return (0);
}
