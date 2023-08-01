/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpicoli- < lpicoli-@student.42porto.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 12:37:26 by lpicoli-          #+#    #+#             */
/*   Updated: 2022/11/25 11:27:03 by lpicoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>
#include <stdio.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	if (!c && !n)
		return (NULL);
	while (i < n)
	{
		if (*(char *)s == (char)c)
			return ((char *)s);
		s++;
		i++;
	}
	if ((char)c == '\0')
		return ((char *)s);
	return (0);
}

/* int main()
{
	char s[] = {0, 1, 2 ,3 ,4 ,5};
	printf("FAKE: %s\n", ((char *) ft_memchr(s, 0, 0)));
	printf("ORIGINAL: %s\n", ((char *) memchr(s, 0, 0)));
} */
