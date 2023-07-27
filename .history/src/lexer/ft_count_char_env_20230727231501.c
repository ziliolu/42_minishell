/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_char_env.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialves-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 11:50:18 by lpicoli-          #+#    #+#             */
/*   Updated: 2023/07/27 23:15:01 by ialves-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

bool	ft_is_not_valid(char c)
{
	if (c == WHITE_SPACE || c == PIPE_LINE
		|| c == SINGLE_QUOTE || c == DOUBLE_QUOTE
		|| c == '\0')
		return (true);
	return (false);
}

int	ft_count_char_env(char *str)
{
	int	i;

	i = 0;
	i++;
	while (str[i] != WHITE_SPACE && str[i] != PIPE_LINE
		&& str[i] != SINGLE_QUOTE && str[i] != DOUBLE_QUOTE
		&& ft_valid_env(str[i]) && str[i] != '\0')
	{
		if (str[i] == '?' && str[i - 1] == '$')
			return (i + 1);
		i++;
	}
	return (i);
}
