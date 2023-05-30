/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_unsigned.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpicoli- < lpicoli-@student.42porto.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 17:41:46 by lpicoli-          #+#    #+#             */
/*   Updated: 2023/02/07 16:58:04 by lpicoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_put_unsigned(unsigned int n)
{
	char	c;

	if (n < 10)
	{
		c = n + 48;
		write (1, &c, 1);
	}
	else
	{
		ft_put_unsigned(n / 10);
		ft_put_unsigned(n % 10);
	}
	return (ft_counter(n));
}
