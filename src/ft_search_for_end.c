/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_search_for_end.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialves-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 23:53:19 by ialves-m          #+#    #+#             */
/*   Updated: 2023/07/20 23:53:34 by ialves-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	*ft_search_for_end(char *str, char c, int pos)
{
	int		i;
	char	*info;

	i = 1;
	while (str[pos + 1] != c)
	{
		info = ft_charjoin(info, str[i]);
		i++;
	}
	if (str[i] == c)
		return (info);
	return (NULL);
}
