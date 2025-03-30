/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enoshahi < enoshahi@student.42abudhabi.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 14:02:45 by enoshahi          #+#    #+#             */
/*   Updated: 2025/02/17 13:40:58 by enoshahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>

int	ft_printf(const char *str, ...);
int	ft_concoct(va_list args, const char format);
int	ft_putchar(char c);
int	ft_puthex(unsigned long num, char base);
int	ft_putnbr(int n);
int	ft_putptr(unsigned long ptr);
int	ft_putstr(char *s);
int	ft_putusd(unsigned int n);

#endif