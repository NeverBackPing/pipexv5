/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_octa _base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjossain <sjossain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 16:18:30 by sjossain          #+#    #+#             */
/*   Updated: 2024/06/12 16:18:30 by sjossain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	convert_to_upper(int conver)
{
	char	dest;

	if (conver < 10)
		dest = conver + 48;
	else
		dest = conver + 55;
	return (dest);
}

char	*ft_base_upper(unsigned int n)
{
	char	*str;
	long	rem;
	int		i;

	str = NULL;
	rem = 0;
	i = 0;
	str = malloc(size_hexa(n) + 1);
	if (!str)
		return (NULL);
	while (n != 0)
	{
		rem = n % 16;
		str[i++] = convert_to_upper(rem);
		n = n / 16;
	}
	str[i] = '\0';
	ft_swap(str);
	return (str);
}
