/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpicoli- < lpicoli-@student.42porto.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 13:28:58 by lpicoli-          #+#    #+#             */
/*   Updated: 2022/11/17 22:19:22 by lpicoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	int	i;

	i = 0;
	while (n > 0)
	{
		((char *)s)[i] = '\0';
		i++;
		n--;
	}
}

/* 
int main()
{
    char s[] = "AAAAAAAAAAAAAA";
    char b[] = "AAAAAAAAAAAAAA";
    
    ft_bzero(s + 2, 4);
    puts(s);
    
    bzero(b + 2, 4);
    puts(b);
} */