/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjossain <sjossain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 16:18:30 by sjossain          #+#    #+#             */
/*   Updated: 2024/06/12 16:18:30 by sjossain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_swap(char *dest)
{
	char	temp;
	int		i;
	int		j;

	i = 0;
	j = ft_strlen(dest) - 1;
	while (i <= j)
	{
		temp = dest[i];
		dest[i] = dest[j];
		dest[j] = temp;
		i++;
		j--;
	}
}
