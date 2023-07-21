/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_if_valid_info_is_dquote.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialves-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 23:57:25 by ialves-m          #+#    #+#             */
/*   Updated: 2023/07/21 01:13:48 by ialves-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_if_valid_info_is_dquote(t_ms *ms, int j, char *str, char *var_info)
{
	str = ft_search_for_end(ms->ms_argv[0], '\"', j);
	if (str != NULL)
		var_info = ft_strjoin(var_info, str);
	while (ms->ms_argv[0][j] != '\"')
		j++;
}
