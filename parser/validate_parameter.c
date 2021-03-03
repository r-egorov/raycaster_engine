/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_parameter.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cisis <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 15:58:08 by cisis             #+#    #+#             */
/*   Updated: 2021/03/03 12:54:23 by cisis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	is_xpm(char *extension)
{
	int		i;

	i = ft_strlen(extension);
	if ((extension[i - 1] == 'm') &&
		(extension[i - 2] == 'p') &&
		(extension[i - 3] == 'x'))
		return (1);
	return (0);
}

static int	is_texture(char *path)
{
	char	*extension;
	char	**splitted;
	int		i;
	int		res;

	if (!(splitted = ft_split(path, '.')))
	{
		g_errno = 2;
		return (0);
	}
	i = 0;
	while (splitted[i])
		i += 1;
	if (i > 2)
	{
		g_errno = 22;
		return (0);
	}
	extension = splitted[i - 1];
	if (is_xpm(extension))
		res = 1;
	else
		res = 0;
	free_strs(splitted);
	return (res);
}

static void	validate_floor_ceiling(char **parameters, t_parsed *parsed,
		int mode)
{
	if (mode == 1)
	{
		if (is_texture(parameters[1]))
			validate_texture(parameters, parsed, 6);
		else
		{
			if (!(g_errno))
				validate_colour(parameters, parsed, 1);
		}
	}
	else if (mode == 2)
	{
		if (is_texture(parameters[1]))
			validate_texture(parameters, parsed, 7);
		else
		{
			if (!(g_errno))
				validate_colour(parameters, parsed, 2);
		}
	}
}

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
	else if (ft_strcmp(parameters[0], "F") == 0)
		validate_floor_ceiling(parameters, parsed, 1);
	else if (ft_strcmp(parameters[0], "C") == 0)
		validate_floor_ceiling(parameters, parsed, 2);
	else if (parameters[0][0] == '1' ||
			parameters[0][0] == '0')
		g_errno = 3;
	else
		g_errno = 10;
	if (g_errno)
		return (0);
	return (1);
}

int			validate_parameters(t_list **begin, t_parsed *parsed)
{
	char	*line;
	char	**parameters;
	int		res;
	int		n_params;
	t_list	*head;

	res = 0;
	n_params = 0;
	head = *begin;
	while (head && n_params < 8)
	{
		line = (char*)head->content;
		if (!(line[0] == '\0'))
		{
			if (!(parameters = ft_split(line, ' ')))
				g_errno = 2;
			if (g_errno || !(parameter_valid(parameters, parsed)))
				res = -1;
			free_strs(parameters);
			n_params += 1;
		}
		head = head->next;
	}
	*begin = head;
	return (res);
}
