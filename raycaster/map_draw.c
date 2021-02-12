/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cisis <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 13:34:57 by cisis             #+#    #+#             */
/*   Updated: 2021/02/12 13:00:38 by cisis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

/*static int	max_str(char **strs)
{
	int		i;
	int		max;
	int		len;

	i = 0;
	max = 0;
	len = 0;
	while (strs[i])
	{
		len = ft_strlen(strs[i]);
		if (len > max)
			max = len; 
	}
	return (max);
}*/

void		draw_square(int	x, int y, t_win *window, int colour)
{
	t_point	topleft;
	int		i;
	int		j;
	
	topleft.x = x * SCALE + 1;	
	topleft.y = y * SCALE + 1;	
	i = 0;
	while (i < SCALE - 1)
	{
		j = 0;
		while (j < SCALE - 1)
		{
			my_mlx_pixel_put(&(window->frame), topleft.x + j, topleft.y + i, colour);
			j++;
		}
		i++;
	}
}

void		draw_map(t_all *all)
{
	int		x;
	int		y;
	t_parsed	*parsed;
	t_win		*window;

	parsed = &(all->parsed);
	window = &(all->window);
	y = 0;
	while ((parsed->map)[y])
	{
		x = 0;
		while ((parsed->map)[y][x])
		{
			if ((parsed->map)[y][x] == '1')
				draw_square(x, y, window, WHITE);
			x++;
		}
		y++;
	}
}
