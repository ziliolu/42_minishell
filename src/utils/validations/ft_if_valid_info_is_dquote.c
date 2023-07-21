/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_if_valid_info_is_dquote.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpicoli- <lpicoli-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 23:57:25 by ialves-m          #+#    #+#             */
/*   Updated: 2023/07/21 11:57:10 by lpicoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

void	ft_if_valid_info_is_dquote(t_ms *ms, int j, char *str, char *var_info)
{
	str = ft_search_for_end(ms->ms_argv[0], '\"', j);
	if (str != NULL)
		var_info = ft_strjoin(var_info, str);
	while (ms->ms_argv[0][j] != '\"')
		j++;
}
