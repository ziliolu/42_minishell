/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_valid_info.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpicoli- <lpicoli-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 23:54:58 by ialves-m          #+#    #+#             */
/*   Updated: 2023/07/21 11:57:33 by lpicoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

bool	ft_is_valid_info(t_ms *ms, int j)
{
	char	*var_info;
	char	*str;

	str = NULL;
	var_info = ft_calloc(ft_strlen(ms->ms_argv[0]), sizeof(char));
	while (ms->ms_argv[0][j])
	{
		if (ms->ms_argv[0][j] == '\"')
			ft_if_valid_info_is_dquote(ms, j, str, var_info);
		else if (ms->ms_argv[0][j] == '\'')
			ft_if_valid_info_is_squote(ms, j, str, var_info);
	}
	if (str == NULL)
	{
		printf("erro!");
		return (false);
	}
	return (true);
}
