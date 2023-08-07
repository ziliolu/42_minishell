/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main_cycle.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialves-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 23:59:46 by ialves-m          #+#    #+#             */
/*   Updated: 2023/08/07 06:04:28 by ialves-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_main_cycle(t_ms *ms, char *read_content, \
	char *tmp_prompt, char *prompt)
{
	read_content = NULL;
	ft_handle_signals();
	if (!ft_main_cycle_read(ms, &read_content, prompt))
		return ;
	if (!read_content)
		return ;
	tmp_prompt = ft_trimmed(read_content);
	if (ft_strcmp(tmp_prompt, "") != 0)
	{
		add_history(read_content);
		ms->read_size = ft_strlen(read_content);
		ft_free(read_content);
		read_content = ft_broken_cmds(ms, tmp_prompt);
		if (read_content)
		{
			ms->ms_env_array = ft_list_to_array(ms);
			ft_if_readline_is_valid(ms, read_content);
			ft_wait(ms);
			ft_free_array(ms->ms_env_array);
		}
	}
	ft_free(read_content);
	ft_free(tmp_prompt);
}

char	*ft_trimmed(char *str)
{
	char	*read_content;
	char	*tmp_content;
	size_t	size;
	size_t	read_size;

	size = 0;
	read_content = ft_strdup(str);
	tmp_content = ft_strdup(str);
	read_size = ft_strlen(str);
	while (read_size != size)
	{
		if (read_content)
			read_size = strlen(read_content);
		free (read_content);
		read_content = ft_strtrim(tmp_content, " ");
		free (tmp_content);
		tmp_content = ft_strtrim(read_content, "	");
		free (read_content);
		read_content = ft_strdup(tmp_content);
		size = strlen(read_content);
	}
	ft_free(tmp_content);
	return (read_content);
}
