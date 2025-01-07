/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexa _base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjossain <sjossain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 16:18:30 by sjossain          #+#    #+#             */
/*   Updated: 2024/06/12 16:18:30 by sjossain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	convert_to_heax(unsigned long conver)
{
	char	dest;

	if (conver < 10)
		dest = conver + 48;
	else
		dest = conver + 'a' - 10;
	return (dest);
}

char	*ft_itoa_base(unsigned long n)
{
	char			*str;
	unsigned int	rem;
	int				i;

	str = NULL;
	rem = 0;
	i = 0;
	str = malloc(size_hexa(n) + 1);
	if (!str)
		return (NULL);
	while (n != 0)
	{
		rem = n % 16;
		str[i++] = convert_to_heax(rem);
		n = n / 16;
	}
	str[i] = '\0';
	ft_swap(str);
	return (str);
}
