/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpicoli- < lpicoli-@student.42porto.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 22:21:23 by lpicoli-          #+#    #+#             */
/*   Updated: 2022/11/17 22:21:48 by lpicoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int c)
{
	return (c >= 0 && c <= 127);
}

/*int main()
{
	int x;

	x = 127;
	printf("FAKE: %d\n", ft_isascii(x));
	printf("ORIGINAL: %d\n", isascii(x));
}*/
