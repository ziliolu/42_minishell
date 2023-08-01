/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpicoli- <lpicoli-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 11:50:18 by lpicoli-          #+#    #+#             */
/*   Updated: 2023/07/31 20:21:18 by lpicoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ft_count_char(char *str)
{
	int	i;

	i = 0;
	while (str[i] != WHITE_SPACE && str[i] != PIPE_LINE
		&& str[i] != SINGLE_QUOTE && str[i] != DOUBLE_QUOTE
		&& str[i] != '$' && str[i] != '\0' && ft_is_not_redir(str[i]))
	{
		i++;
	}
	return (i);
}
