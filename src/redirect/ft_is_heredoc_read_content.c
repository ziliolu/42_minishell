/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_heredoc_read_content.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpicoli- <lpicoli-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 10:01:08 by lpicoli-          #+#    #+#             */
/*   Updated: 2023/08/01 09:13:20 by lpicoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*ft_expand_heredoc(t_lst *env, t_lst *vars, char *variable)
{
	char	*str;

	str = NULL;
	if (ft_strcmp(variable, "$") == 0)
		return (ft_strdup(variable));
	str = ft_strtrim(variable, "$");
	if (ft_strcmp(str, "?") == 0)
	{
		ft_free(str);
		return (ft_itoa(g_exit_status));
	}
	while (env)
	{
		if (ft_strcmp(str, env->name) == 0)
			return (ft_expand_while_env(env, vars, str));
		env = env->next;
	}
	while (vars)
	{
		if (ft_strcmp(str, vars->name) == 0)
			return (ft_expand_while_vars(env, vars, str));
		vars = vars->next;
	}
	free(str);
	return (ft_strdup(variable));
}

bool	ft_is_ctrld(t_command *cmd, t_heredoc *h, char **tmp)
{
	if (!h->read_content)
	{
		cmd->err = true;
		printf("minishell: warning:");
		printf("here-document delimited by end-of-file (wanted `%s')\n", h->eof);
		ft_free(*tmp);
		return (true);
	}
	return (false);
}

void	ft_join_heredoc_inputs(t_ms *ms, t_heredoc *h, char **tmp)
{
	if (!*tmp)
	{
		*tmp = ft_expand_heredoc(ms->ms_env, *ms->vars, h->read_content);
		h->str = ft_expand_heredoc(ms->ms_env, *ms->vars, h->read_content);
	}
	else
	{
		ft_free(h->str);
		h->str = ft_strjoin(*tmp, "\n");
		ft_free(*tmp);
		*tmp = ft_strjoin(h->str, \
		ft_expand_heredoc(ms->ms_env, *ms->vars, h->read_content));
		ft_free(h->str);
		h->str = ft_strdup(*tmp);
	}
}

char	*ft_is_heredoc_read_content(t_ms *ms, t_command *cmd, t_heredoc *h)
{
	char	*tmp;

	tmp = NULL;
	ms->pid = fork();
	if (ms->pid == 0)
	{
		g_exit_status = 0;
		while (ft_strcmp(h->read_content, h->eof) != 0)
		{
			//ft_free(h->read_content);
			h->read_content = readline(h->prompt);
			if (ft_is_ctrld(cmd, h, &tmp))
				return (h->str);
			else
			{
				if (ft_strcmp(h->read_content, h->eof) == 0)
					break ;
				ft_join_heredoc_inputs(ms, h, &tmp);
			}
		}
	}
	ft_free(h->read_content);
	ft_free(tmp);
	return (h->str);
}
