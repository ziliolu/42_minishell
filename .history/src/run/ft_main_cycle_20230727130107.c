/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main_cycle.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialves-m <ialves-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 23:59:46 by ialves-m          #+#    #+#             */
/*   Updated: 2023/07/27 13:01:07 by ialves-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_main_cycle(t_ms *ms, char *read_content, \
	char *tmp_prompt, char *prompt)
{
	ft_main_cycle_read(ms, read_content, tmp_prompt, prompt);
	tmp_prompt = ft_strtrim(read_content, " ");
	if (ft_strcmp(tmp_prompt, "") != 0)
	{
		add_history(read_content);
		ms->read_size = ft_strlen(read_content);
		ft_free(read_content);
		read_content = ft_broken_cmds(ms, tmp_prompt);
		ft_free(tmp_prompt);
		if (!read_content)
			return ;
		ft_if_readline_is_valid(ms, read_content);
		ft_wait(ms);
		ft_free_array(ms->ms_env_array);
		ft_free(read_content);
	}
	else
	{
		ft_free(read_content);
		ft_free(tmp_prompt);
	}
}
