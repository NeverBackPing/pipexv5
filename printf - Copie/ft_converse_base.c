/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_converse_base.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjossain <sjossain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 16:29:27 by sjossain          #+#    #+#             */
/*   Updated: 2024/03/27 01:08:54 by sjossain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_converse_base(char *format, va_list copy)
{
	size_t	i;
	int		count;

	i = 0;
	count = 0;
	if (format[i] == 'p')
		count += get_hexa_base((char *)&format[i], copy);
	if (format[i] == 'x')
		count += get_hexa_lower((char *)&format[i], copy);
	if (format[i] == 'X')
		count += get_hexa_upper((char *)&format[i], copy);
	return (count);
}

int	get_hexa_upper(char *format, va_list copy)
{
	int			i;
	char		*str;
	int			count;
	long		nb;

	i = 0;
	count = 0;
	nb = 0;
	if (format[i] == 'X')
	{
		nb = va_arg(copy, unsigned int);
		if (!nb)
			return (ft_putstr("0"), 1);
		str = ft_base_upper(nb);
		if (!str)
			return (0);
		count += ft_strlen(str);
		ft_putstr(str);
		free(str);
	}
	return (count);
}

int	get_hexa_lower(char *format, va_list copy)
{
	int			i;
	char		*str;
	int			count;
	long		nb;

	i = 0;
	count = 0;
	nb = 0;
	if (format[i] == 'x')
	{
		nb = va_arg(copy, unsigned int);
		if (!nb)
			return (ft_putstr("0"), 1);
		str = ft_itoa_base(nb);
		if (!str)
			return (0);
		count += ft_strlen(str);
		ft_putstr(str);
		free(str);
	}
	return (count);
}

int	get_hexa_base(char *format, va_list copy)
{
	int		i;
	char	*str;
	int		count;
	long	nb;

	i = 0;
	count = 0;
	nb = 0;
	if (format[i] == 'p')
	{
		nb = va_arg(copy, unsigned long);
		if (!nb)
			return (ft_putstr("(nil)"), 5);
		str = ft_itoa_base(nb);
		if (!str)
			return (0);
		count += ft_strlen(str);
		ft_putstr("0x");
		count += ft_strlen("0x");
		ft_putstr(str);
		free(str);
	}
	return (count);
}
