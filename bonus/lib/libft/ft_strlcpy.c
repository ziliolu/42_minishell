/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpicoli- < lpicoli-@student.42porto.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 09:04:26 by lpicoli-          #+#    #+#             */
/*   Updated: 2022/11/17 22:54:28 by lpicoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	int		src_len;

	i = 0;
	src_len = ft_strlen(src);
	if (size < 1)
		return (src_len);
	while (src[i] && i < (size - 1))
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (src_len);
}

/*int main()
{
	char src[] = "12";
	char dst[] = "abc";

	char src2[] = "12";
	char dst2[] = "abc";

	puts(dst);
	ft_strlcpy(dst, src, 5);
	puts(dst);
}*/