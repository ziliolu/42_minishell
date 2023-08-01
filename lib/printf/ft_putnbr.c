/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpicoli- < lpicoli-@student.42porto.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 13:19:24 by lpicoli-          #+#    #+#             */
/*   Updated: 2023/02/07 16:58:27 by lpicoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int n)
{
	int	signal;

	signal = 0;
	if (n == INT_MIN)
		return (ft_putstr("-2147483648"));
	if (n < 0)
	{
		n *= -1;
		ft_putchar('-');
		signal = 1;
	}
	if (n < 10)
		ft_putchar(n + '0');
	else
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
	return (ft_counter(n) + signal);
}
