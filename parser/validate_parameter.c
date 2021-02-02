/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_parameter.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cisis <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 15:58:08 by cisis             #+#    #+#             */
/*   Updated: 2021/02/02 11:59:09 by cisis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	parameter_valid(char **parameters, t_parsed *parsed)
{
	if (ft_strcmp(parameters[0], "R") == 0)
		validate_resolution(parameters, parsed);
	else if (ft_strcmp(parameters[0], "NO") == 0)
		validate_texture(parameters, parsed, 1);
	else if (ft_strcmp(parameters[0], "SO") == 0)
		validate_texture(parameters, parsed, 2);
	else if (ft_strcmp(parameters[0], "WE") == 0)
		validate_texture(parameters, parsed, 3);
	else if (ft_strcmp(parameters[0], "EA") == 0)
		validate_texture(parameters, parsed, 4);
	else if (ft_strcmp(parameters[0], "S") == 0)
		validate_texture(parameters, parsed, 5);
	/*else if (ft_strcmp(parameters[0], "F") == 0)
		validate_colour(parameters, parsed, 1);
	else if (ft_strcmp(parameters[0], "C") == 0)
		validate_colour(parameters, parsed, 2);*/
	else
		//g_errno = 10; // WILL BE NEEDED WHEN EVERY PARAM DONE
	if (g_errno)
		return (0);
	return (1);
}

// PRINTF
void		print_strs(char **strs)
{
	int i = 0;
	while (strs[i])
	{
		printf("%s\n", strs[i]);
		i++;
	}
}

int			validate_parameter(void *content, t_parsed *parsed)
{
	char	*line;
	char	**parameters;
	int		res;

	line = (char*)content;

	if (!(parameters = ft_split(line, ' ')))
	{
		g_errno = 2;
		return (-1);
	}
	if (parameter_valid(parameters, parsed))
		res = 0;
	else
		res = -1;
	free_strs(parameters);
	return (res);
}
