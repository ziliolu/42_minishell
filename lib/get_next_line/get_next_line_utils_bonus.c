/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpicoli- < lpicoli-@student.42porto.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 16:08:28 by lpicoli-          #+#    #+#             */
/*   Updated: 2023/02/07 16:14:45 by lpicoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*ptr;
	int		i;
	int		n;

	i = 0;
	n = nmemb * size;
	ptr = malloc(nmemb * size);
	if (!ptr)
		return (NULL);
	while (n-- > 0)
		ptr[i++] = '\0';
	return (ptr);
}

int	ft_find_newline(char *ptr)
{
	int	i;

	i = 0;
	if (!ptr)
		return (0);
	while (ptr[i])
	{
		if (ptr[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_join_stash(char *stash, char *buffer)
{
	char	*tmp;
	int		i;
	int		j;

	if (!stash)
		stash = ft_calloc(1, sizeof(char));
	if (!buffer)
		return (NULL);
	i = 0;
	j = 0;
	tmp = ft_calloc((ft_strlen(stash) + ft_strlen(buffer) + 1), sizeof(char));
	while (stash[i])
	{
		tmp[i] = stash[i];
		i++;
	}
	while (buffer[j])
		tmp[i++] = buffer[j++];
	free(stash);
	return (tmp);
}
