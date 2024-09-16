/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjossain <sjossain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 13:03:55 by sjossain          #+#    #+#             */
/*   Updated: 2024/06/10 13:03:55 by sjossain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

size_t	size_hexa(unsigned long n)
{
	size_t	len;
	long	rem;

	len = 0;
	rem = 0;
	while (n != 0)
	{
		rem = n % 16;
		n = n / 16;
		len++;
	}
	n = rem;
	return (len);
}
