/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialves-m <ialves-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 12:26:35 by lpicoli-          #+#    #+#             */
/*   Updated: 2023/07/25 12:23:41 by ialves-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_new_line(char *stash)
{
	char	*tmp;
	int		i;

	if (!*stash)
		return (NULL);
	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	tmp = ft_calloc(i + 2, sizeof(char));
	i = 0;
	while (stash[i] && stash[i] != '\n')
	{
		tmp[i] = stash[i];
		i++;
	}
	tmp[i] = stash[i];
	return (tmp);
}

char	*get_rest(char *stash)
{
	char	*tmp;
	int		i;
	int		index;

	index = 0;
	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	if (!*stash)
	{
		free(stash);
		return (NULL);
	}
	tmp = ft_calloc(ft_strlen(stash) - i + 1, sizeof(char));
	while (stash[i])
		tmp[index++] = stash[++i];
	tmp[index] = '\0';
	free(stash);
	return (tmp);
}

void	*ft_free(char **stash, char **buffer)
{
	free(*buffer);
	free(*stash);
	*stash = NULL;
	return (NULL);
}

char	*get_next_line(int fd)
{
	int				read_len;
	char			*buffer;
	char			*line;
	static char		*stash;

	read_len = BUFFER_SIZE;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	while (!(ft_find_newline(buffer)) && read_len != 0)
	{
		read_len = read(fd, buffer, BUFFER_SIZE);
		if (read_len == -1)
			return (ft_free(&stash, &buffer));
		buffer[read_len] = '\0';
		stash = ft_join_stash(stash, buffer);
	}
	line = get_new_line(stash);
	stash = get_rest(stash);
	free(buffer);
	return (line);
}

/* int main()
{
    int fd;

    char *ptr;
    fd = open("text.txt", O_RDONLY);
    ptr = get_next_line(fd);
    printf("%s", ptr);
    free(ptr);

    ptr = get_next_line(fd);
    printf("%s", ptr);
    free(ptr);

    ptr = get_next_line(fd);
    printf("%s", ptr);
    free(ptr);
} */