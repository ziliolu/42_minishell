/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpicoli- < lpicoli-@student.42porto.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 18:39:34 by lpicoli-          #+#    #+#             */
/*   Updated: 2022/12/10 18:44:49 by lpicoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthexa(unsigned long n, char *base)
{
	if (n == 0)
		return (write(1, "0", 1));
	else
	{
		if (n < 16)
			ft_putchar(base[n]);
		else
		{
			ft_puthexa(n / 16, base);
			ft_puthexa(n % 16, base);
		}
		return (ft_hexlen(n));
	}	
}
