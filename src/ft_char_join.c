/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char_join.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialves-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 23:52:11 by ialves-m          #+#    #+#             */
/*   Updated: 2023/07/20 23:52:52 by ialves-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	*ft_charjoin(char *str, char c)
{
	int		i;
	char	*new_str;

	new_str = ft_calloc(2, sizeof(str));
	i = -1;
	while (str[++i])
		new_str[i] = str[i];
	new_str[++i] = c;
	new_str[++i] = '\0';
	return (new_str);
}
