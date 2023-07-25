/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialves-m <ialves-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 20:49:02 by lpicoli-          #+#    #+#             */
/*   Updated: 2023/07/25 12:25:44 by ialves-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_words(char *str, char c)
{
	int	flag;
	int	i;
	int	words;

	flag = 1;
	i = 0;
	words = 0;
	while (str[i])
	{
		while (str[i] == c)
			i++;
		while (str[i] != c && str[i])
		{
			if (flag == 1)
			{
				words++;
				flag = 0;
			}
			i++;
		}
		flag = 1;
	}
	return (words);
}

static char	*ft_fulfill_tab(char *s, char c, size_t *i)
{
	int	start;

	while (s[*i] == c)
		(*i)++;
	start = *i;
	while (s[*i] && s[*i] != c)
		(*i)++;
	return (ft_substr(s, start, *i - start));
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	size_t	size;
	size_t	i;
	size_t	k;

	size = ft_count_words((char *)s, c);
	i = 0;
	k = 0;
	tab = malloc((size + 1) * sizeof(char *));
	while (s[i] && k < size)
	{
		tab[k] = ft_fulfill_tab((char *)s, c, &i);
		k++;
	}
	tab[k] = NULL;
	return (tab);
}

// int main()
// {
//     char **tab;
//     int i = 0;
//     tab = ft_split("lorem ipsum dolor sit amet", ' ');
//     while(tab[i])
//     {
//         printf("tab[%d]: %s\n", i, tab[i]);
// 		free (tab[i]);
//         i++;
//     }
// 	free (tab);
// }
