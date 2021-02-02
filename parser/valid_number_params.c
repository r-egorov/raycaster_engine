/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_number_params.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cisis <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 11:34:16 by cisis             #+#    #+#             */
/*   Updated: 2021/02/02 11:48:13 by cisis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int			valid_number_params(char **parameters, size_t num_params)
{
	size_t	count;

	count = 0;
	while (parameters[count])
		count++;
	if (count != num_params)
	{
		g_errno = 11;
		return (0);
	}
	return (1);
}
