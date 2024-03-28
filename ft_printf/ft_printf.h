/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tabadawi <tabadawi@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 20:47:50 by tabadawi          #+#    #+#             */
/*   Updated: 2024/03/28 15:25:23 by tabadawi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

int	ft_format(char c, va_list args);
int	ft_printf(const char *str, ...);
int	ft_putchar(char c);
int	ft_puthex(unsigned long long nbr, unsigned int letter);
int	ft_putnbr(int nbr);
int	ft_putpointer(void *p);
int	ft_putstr(char *str);
int	printf_strlen(char *str);
int	ft_putusnbr(unsigned int nbr);

#endif