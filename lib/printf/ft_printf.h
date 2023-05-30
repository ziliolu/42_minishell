/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpicoli- < lpicoli-@student.42porto.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 13:48:34 by lpicoli-          #+#    #+#             */
/*   Updated: 2023/02/07 16:57:09 by lpicoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>
# include <limits.h>
# include <stdlib.h>
# include "../libft/libft.h" 

int		ft_printf(const char *format, ...);
int		ft_filter_format(char c, va_list ap);
int		ft_hexlen(unsigned long n);
int		ft_putchar(char c);
int		ft_puthexa(unsigned long n, char *base);
int		ft_putnbr(int n);
int		ft_putstr(char *str);
//int		ft_strlen(char *str);
int		ft_putptr(void *ptr);
int		ft_counter(long n);
int		ft_put_unsigned(unsigned int n);

#endif