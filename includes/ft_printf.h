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

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdarg.h>
# include <limits.h>

int		check_type(char *format, va_list copy);
int		ft_converse_base(char *format, va_list copy);
int		get_char(char *format, va_list copy);
int		get_hexa_base(char *format, va_list copy);
int		get_hexa_lower(char *format, va_list copy);
int		get_hexa_upper(char *format, va_list copy);
int		get_int(char *format, va_list copy);
char	*ft_base_upper(unsigned int n);
char	*ft_itoa(int n);
char	*ft_itoa_base(unsigned long n);
char	*ft_itoa_byte32(unsigned int n);
int		ft_printf(const char *format, ...);
size_t	ft_printf_usigned(char *format, va_list copy);
int		ft_putstr(char *s);
int		ft_putchar(char c);
void	ft_putnbr(int n);
size_t	ft_strlen(const char *s);
void	ft_swap(char *dest);
size_t	size_hexa(unsigned long n);
#endif