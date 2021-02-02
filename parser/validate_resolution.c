/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_resolution.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cisis <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 16:41:32 by cisis             #+#    #+#             */
/*   Updated: 2021/02/02 11:37:00 by cisis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	validate_number(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (-1);
		i++;
	}
	return (ft_atoi(str));
}

static void	set_height(int parameter_height, t_parsed *parsed)
{
	if (parameter_height > g_screen_height)
		parsed->res_height = g_screen_height;
	else
		parsed->res_height = parameter_height;
}

static void	set_width(int parameter_width, t_parsed *parsed)
{
	if (parameter_width > g_screen_width)
		parsed->res_width = g_screen_width;
	else
		parsed->res_width = parameter_width;
}

void		validate_resolution(char **parameters, t_parsed *parsed)
{
	int		height_param;
	int		width_param;

	if (!(valid_number_params(parameters, 3)))
		return ;
	if (((width_param = validate_number(parameters[1])) == -1) ||
		((height_param = validate_number(parameters[2])) == -1))
	{
		g_errno = 12;
		return ;
	}
	set_width(width_param, parsed);
	set_height(height_param, parsed);
}
