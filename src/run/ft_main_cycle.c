/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main_cycle.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialves-m <ialves-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 23:59:46 by ialves-m          #+#    #+#             */
/*   Updated: 2023/08/12 15:35:58 by ialves-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_free_input(char *read_content, char *tmp_prompt)
{
	ft_free(read_content);
	ft_free(tmp_prompt);
}

void	ft_main_cycle(t_ms *ms, char *read_content, \
	char *tmp_prompt, char *prompt)
{
	read_content = NULL;
	ft_handle_signals();
	if (!ft_main_cycle_read(ms, &read_content, prompt))
		return ;
	tmp_prompt = ft_trimmed(read_content);
	if (ft_strcmp(tmp_prompt, "") != 0)
	{
		add_history(read_content);
		ms->read_size = ft_strlen(read_content);
		ft_free(read_content);
		read_content = ft_broken_cmds(ms, tmp_prompt);
		ft_free(tmp_prompt);
		ms->clean_read_content = read_content;
		if (read_content)
		{
			ms->ms_env_array = ft_list_to_array(ms);
			ft_if_readline_is_valid(ms, read_content);
			ft_wait(ms);
			ft_free_array(ms->ms_env_array);
		}
	}
	else
		ft_free_input(read_content, tmp_prompt);
}

char	*ft_trimmed_read(char *read_, char *tmp_)
{
	if (ft_strlen(tmp_) > 0)
		read_ = ft_strtrim(tmp_, " ");
	else
		read_ = ft_strdup("");
	return (read_);
}

char	*ft_trimmed_tmp(char *read_, char *tmp_)
{
	if (ft_strlen(read_) > 0)
		tmp_ = ft_strtrim(read_, " ");
	else
		tmp_ = ft_strdup("");
	return (tmp_);
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
		read_content = ft_trimmed_read(read_content, tmp_content);
		free (tmp_content);
		tmp_content = ft_trimmed_tmp(read_content, tmp_content);
		free (read_content);
		read_content = ft_strdup(tmp_content);
		size = strlen(read_content);
	}
	ft_free(tmp_content);
	return (read_content);
}
