/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjossain <sjossain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 11:16:40 by sjossain          #+#    #+#             */
/*   Updated: 2024/06/10 11:16:40 by sjossain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_putstr(char *s)
{
	size_t	i;
	int		len;

	i = 0;
	len = 0;
	while (s[i] != '\0')
	{
		ft_putchar(s[i]);
		i++;
		len++;
	}
	return (len);
}
