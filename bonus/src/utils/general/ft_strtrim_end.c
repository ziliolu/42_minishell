/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim_end.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialves-m <ialves-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 10:52:56 by lpicoli-          #+#    #+#             */
/*   Updated: 2023/07/25 12:18:18 by ialves-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

char	*ft_strtrim_end(char *str, char set)
{
	int		i;
	char	*new_str;

	i = ft_strlen(str);
	if (str[i] == set)
	{
		new_str = ft_calloc(i - 1, sizeof(char));
		ft_strlcpy(new_str, str, i - 1);
		return (new_str);
	}
	return (ft_strdup(str));
}
