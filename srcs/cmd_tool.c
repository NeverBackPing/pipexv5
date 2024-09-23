/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_tool.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjossain <sjossain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 13:15:17 by sjossain          #+#    #+#             */
/*   Updated: 2024/09/23 13:16:28 by sjossain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	check_space(char *av)
{
	int	i;
	int	check;

	i = 0;
	check = 0;
	while (av[i] != '\0')
	{
		if (av[i] != ' ')
			check = 1;
		i++;
	}
	if (check == 1)
		return (0);
	return (1);
}
