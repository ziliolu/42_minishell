/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpicoli- < lpicoli-@student.42porto.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 13:03:22 by lpicoli-          #+#    #+#             */
/*   Updated: 2022/11/17 22:49:45 by lpicoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*ptr1;
	unsigned char	*ptr2;

	ptr1 = (unsigned char *)s1;
	ptr2 = (unsigned char *)s2;
	i = 0;
	if (n == 0)
		return (0);
	while (i < n && (*(ptr1 + i) || *(ptr2 + i)))
	{
		if (*(ptr1 + i) != *(ptr2 + i))
			return (*(ptr1 + i) - *(ptr2 + i));
		i++;
	}
	return (0);
}

/* int main()
{
	printf("FAKE: %d\n", ft_strncmp("abcdefgh", "abcdwxyz", 4));
	printf("ORIGINAL: %d\n", strncmp("abcdefgh", "abcdwxyz", 4));
}
 */