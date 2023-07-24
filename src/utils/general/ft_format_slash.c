/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_slash.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialves-m <ialves-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 14:02:56 by lpicoli-          #+#    #+#             */
/*   Updated: 2023/07/24 22:40:33 by ialves-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

char	*ft_format_slash(char *str)
{
	char	*new_str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (ft_strchr(str, '\\'))
	{
		while (str[i])
		{
			new_str = ft_calloc(sizeof(char), ft_strlen(str) - 1);
			if (str[i] == '\\')
			{
				i++;
			}
			new_str[j] = str[i];
			i++;
			j++;
		}
		free(str);
		return (new_str);
	}
	return (str);
}
