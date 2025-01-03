/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_usigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjossain <sjossain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 16:29:27 by sjossain          #+#    #+#             */
/*   Updated: 2024/03/27 01:08:54 by sjossain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

size_t	check_byte32(unsigned int nb)
{
	size_t	len;

	len = 0;
	while (nb >= 10)
	{
		nb = nb / 10;
		len++;
	}
	len++;
	return (len);
}

char	*ft_itoa_byte32(unsigned int n)
{
	int		i;
	char	*dest;

	i = 0;
	dest = malloc((check_byte32(n) + 1) * sizeof(char));
	if (dest == NULL)
		return (NULL);
	while (n)
	{
		dest[i++] = n % 10 + '0';
		n = n / 10;
	}
	dest[i] = '\0';
	ft_swap(dest);
	return (dest);
}

size_t	ft_printf_usigned(char *format, va_list copy)
{
	unsigned int	result;
	int				i;
	char			*str;
	int				count;

	i = 0;
	count = 0;
	result = 0;
	if (format[i] == 'u')
	{
		result = va_arg(copy, unsigned int);
		if (result == 0)
			return (ft_putstr("0"), 1);
		str = ft_itoa_byte32(result);
		if (!str)
			return (0);
		count += ft_strlen(str);
		ft_putstr(str);
		if (result == 0)
			return (1);
		free(str);
	}
	return (count);
}
