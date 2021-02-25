/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_colour.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cisis <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 12:18:10 by cisis             #+#    #+#             */
/*   Updated: 2021/02/25 18:37:44 by cisis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

static int	invalid_chars(char *colour_str)
{
	size_t		i;

	i = 0;
	while (colour_str[i])
	{
		if ((colour_str[i] != ',') &&
			(!(colour_str[i] >= '0' && colour_str[i] <= '9')))
		{
			g_errno = 15;
			return (1);
		}
		i++;
	}
	return (0);
}

static int	validate_colour_value(char *str)
{
	int		res;

	res = ft_atoi(str);
	if ((res < 0) || (res > 255))
		return (-1);
	return (res);
}

static void	validate_rgb(char **nums_strs, t_parsed *parsed, int mode)
{
	int		r;
	int		g;
	int		b;
	int		rgb;

	if (((r = validate_colour_value(nums_strs[0])) == -1) ||
		((g = validate_colour_value(nums_strs[1])) == -1) ||
		((b = validate_colour_value(nums_strs[2])) == -1))
	{
		g_errno = 16;
		return ;
	}
	rgb = 0;
	rgb = (r << 16 | g << 8 | b);
	if ((mode == 1) && (parsed->floor_texture_path || parsed->floor_colour))
		g_errno = 30;
	else if (mode == 1)
		parsed->floor_colour = rgb;
	else if ((mode == 2) &&
			(parsed->ceiling_texture_path || parsed->ceiling_colour))
		g_errno = 31;
	else if (mode == 2)
		parsed->ceiling_colour = rgb;
}

void		validate_colour(char **parameters, t_parsed *parsed, int mode)
{
	char	**nums_strs;
	size_t	i;

	if ((!(valid_number_params(parameters, 2))))
	{
		g_errno = 17;
		return ;
	}
	if (invalid_chars(parameters[1]))
		return ;
	if (!(nums_strs = ft_split(parameters[1], ',')))
	{
		g_errno = 2;
		return ;
	}
	i = 0;
	validate_rgb(nums_strs, parsed, mode);
	free_strs(nums_strs);
}
