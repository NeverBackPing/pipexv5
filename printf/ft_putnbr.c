/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjossain <sjossain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 11:16:31 by sjossain          #+#    #+#             */
/*   Updated: 2024/06/10 11:16:31 by sjossain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_putnbr(int n)
{
	long	neg;
	char	c;

	neg = 0;
	if (n < 0)
	{
		ft_putchar('-');
		neg = (long)n * -1;
	}
	else
		neg = (long)n * 1;
	if (neg >= 10)
		ft_putnbr(neg / 10);
	c = neg % 10 + '0';
	ft_putchar(c);
}
