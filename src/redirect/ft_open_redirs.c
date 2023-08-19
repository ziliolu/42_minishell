/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_open_redirs.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialves-m <ialves-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 10:01:08 by lpicoli-          #+#    #+#             */
/*   Updated: 2023/08/12 16:13:10 by ialves-m         ###   ########.fr       */
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
				if (ft_open_redirs_if_var(ms, c, tmp_arg))
					return (ft_error_var_start("ambiguous redirect", \
						ms->cmds[c->i].redirs[c->k].arg, 1));
				if (!ft_open_redirs_if_others(ms, c))
					return (false);
			}
			if (ms->cmds[c->i].redirs[c->k - 1].type == REDIR_OUT)
				ms->cmds[c->i].out = open(ms->cmds[c->i].redirs[c->k - 1].arg, \
					O_CREAT | O_TRUNC | O_WRONLY, 0644);
			else if (ms->cmds[c->i].redirs[c->k - 1].type == D_REDIR_OUT)
				ms->cmds[c->i].out = open(ms->cmds[c->i].redirs[c->k - 1].arg, \
					O_CREAT | O_APPEND | O_WRONLY, 0644);
		}
	}
	return (true);
}
