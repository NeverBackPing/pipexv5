/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjossain <sjossain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 10:30:34 by sjossain          #+#    #+#             */
/*   Updated: 2024/06/14 14:46:54 by sjossain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	get_char(char *format, va_list copy)
{
	int		i;
	char	*str;
	int		count;

	i = 0;
	count = 0;
	if (format[i] == 's')
	{
		str = va_arg(copy, char *);
		if (!str)
			return (ft_putstr("(null)"), 6);
		count += ft_strlen(str);
		ft_putstr(str);
	}
	return (count);
}

int	get_int(char *format, va_list copy)
{
	int		result;
	int		i;
	char	*str;
	int		count;

	i = 0;
	count = 0;
	result = 0;
	if (format[i] == 'd' || format[i] == 'i')
	{
		result = va_arg(copy, int);
		str = ft_itoa(result);
		if (!str)
			return (0);
		count += ft_strlen(str);
		ft_putstr(str);
		free(str);
	}
	if (format[i] == 'c')
	{
		result = va_arg(copy, int);
		count += ft_putchar(result);
	}
	return (count);
}

int	check_type(char *format, va_list copy)
{
	size_t	i;
	int		count;

	i = 0;
	count = 0;
	if (format[i + 1] == '%')
		count += ft_putchar('%');
	else
	{
		i++;
		if (format[i] == 'd')
			count += get_int((char *)&format[i], copy);
		if (format[i] == 'c')
			count += get_int((char *)&format[i], copy);
		if (format[i] == 's')
			count += get_char((char *)&format[i], copy);
		if (format[i] == 'u')
			count += ft_printf_usigned((char *)&format[i], copy);
		if (format[i] == 'i')
			count += get_int((char *)&format[i], copy);
		if (format[i] == 'X' || format[i] == 'x' || format[i] == 'p')
			count += ft_converse_base((char *)&format[i], copy);
	}
	return (count);
}

int	ft_printf(const char *format, ...)
{
	int		count;
	size_t	i;
	va_list	copy;

	i = 0;
	count = 0;
	if (!format)
		return (-1);
	va_start(copy, format);
	while (format[i] != '\0')
	{
		if (format[i] != '%')
		{
			count += ft_putchar(format[i]);
		}
		else
		{
			count += check_type((char *)&format[i], copy);
			i++;
		}
		i++;
	}
	va_end(copy);
	return (count);
}
