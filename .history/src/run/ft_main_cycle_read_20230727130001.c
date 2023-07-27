/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main_cycle_read.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialves-m <ialves-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 23:59:46 by ialves-m          #+#    #+#             */
/*   Updated: 2023/07/27 13:00:01 by ialves-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_main_cycle_rea(t_ms *ms, char *read_content, \
	char *tmp_prompt, char *prompt)
{
	ms->processes = 0;
	ft_handle_signals();
	read_content = readline(prompt);
	ft_is_not_read_content(ms, read_content);
	if (ft_strcmp(read_content, "") == 0)
	{
		ft_free(read_content);
		return ;
	}
}
