/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char_join.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpicoli- <lpicoli-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 23:52:11 by ialves-m          #+#    #+#             */
/*   Updated: 2023/07/28 15:41:28 by lpicoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

char	*ft_charjoin(char *str, char c)
{
	int		i;
	char	*new_str;

	if(str)
		new_str = ft_calloc(ft_strlen(str) + 1, sizeof(char));
	else
		new_str = ft_calloc(2, sizeof(char));
	i = 0;
	while (str && str[i])
	{
		new_str[i] = str[i];
		i++;
	}
	new_str[i] = c;
	new_str[++i] = '\0';
	return (new_str);
}
