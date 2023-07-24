/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim_end_quote.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialves-m <ialves-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 10:52:56 by lpicoli-          #+#    #+#             */
/*   Updated: 2023/07/24 22:43:53 by ialves-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

char	*ft_strtrim_end_quote(char *str, char set)
{
	int		i;
	int		j;
	char	*new_str;

	i = ft_strlen(str);
	while (i >= 0)
	{
		if (str[i] == set)
		{
			j = i;
			new_str = ft_calloc(j + 1, sizeof(char));
			ft_strlcpy(new_str, str, j + 1);
			return (new_str);
		}
		i--;
	}
	return (str);
}
