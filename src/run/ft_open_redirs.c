/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_open_redirs.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialves-m <ialves-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 10:01:08 by lpicoli-          #+#    #+#             */
/*   Updated: 2023/07/22 21:41:13 by ialves-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

bool	ft_open_redirs(t_ms *ms, t_counters *c)
{
	char	*tmp_arg;

	tmp_arg = NULL;
	if (ms->cmds[c->i].type == CMD)
	{
		if (ms->cmds[c->i].redirs[c->k].arg != NULL)
		{
			while (c->k < ft_count_redirs_cmd(&ms->cmds[c->i]))
			{
				ft_open_redirs_if_var(ms, c, tmp_arg);
				if (ms->cmds[c->i].redirs[c->k].arg[0] == '$')
				{
					tmp_arg = ft_strtrim(ms->cmds[c->i].redirs[c->k].arg, "$");
					if (!ft_is_already_in_list(tmp_arg, *ms->vars) && !ft_is_already_in_list(tmp_arg, ms->ms_env))
					{
						ft_free(tmp_arg);
						return (ft_error_var_start("ambiguous redirect", ms->cmds[c->i].redirs[c->k].arg, 1));
					}
					ft_free(ms->cmds[c->i].redirs[c->k].arg);
					if (ft_is_already_in_list(tmp_arg, ms->ms_env))
						ms->cmds[c->i].redirs[c->k].arg = ft_return_list_info(ms->ms_env, tmp_arg);
					else if (ft_is_already_in_list(tmp_arg, *ms->vars))
						ms->cmds[c->i].redirs[c->k].arg = ft_return_list_info(*ms->vars, tmp_arg);
					ft_free(tmp_arg);
				}
				ft_open_redirs(ms, c);	
				if (ms->cmds[c->i].redirs[c->k].type == REDIR_OUT || ms->cmds[c->i].redirs[c->k].type == D_REDIR_OUT)
					ms->cmds[c->i].out = open(ms->cmds[c->i].redirs[c->k].arg, O_CREAT | O_APPEND | O_WRONLY, 0777);
				else if (ms->cmds[c->i].redirs[c->k].type == REDIR_IN)
				{
					if (open(ms->cmds[c->i].redirs[c->k].arg, O_RDONLY, 0777) != -1)
						ms->cmds[c->i].in = open(ms->cmds[c->i].redirs[c->k].arg, O_RDONLY, 0777);
					else
					{
						ms->cmds[c->i].err = true;
						ft_error_var_start("No such file or directory", ms->cmds[c->i].redirs[c->k].arg, 1);
					}
					if (!ms->cmds[c->i + 1].args)
						return (false);
				}
				else if (ms->cmds[c->i].redirs[c->k].type == HERE_DOC)
					ft_is_heredoc(&ms->cmds[c->i], &ms->cmds[c->i].redirs[c->k]);
				c->k++;
			}
			if (ms->cmds[c->i].redirs[c->k - 1].type == REDIR_OUT)
				ms->cmds[c->i].out = open(ms->cmds[c->i].redirs[c->k - 1].arg, O_CREAT | O_TRUNC | O_WRONLY, 0777);
			else if (ms->cmds[c->i].redirs[c->k - 1].type == D_REDIR_OUT)
				ms->cmds[c->i].out = open(ms->cmds[c->i].redirs[c->k - 1].arg, O_CREAT | O_APPEND | O_WRONLY, 0777);
		}
	}
	return (true);
}
