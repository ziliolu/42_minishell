/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_open_redirs_if_others.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialves-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 10:01:08 by lpicoli-          #+#    #+#             */
/*   Updated: 2023/08/07 04:33:52 by ialves-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

bool	ft_open_redirs_if_others(t_ms *ms, t_counters *c)
{
	if (ms->cmds[c->i].redirs[c->k].type == REDIR_OUT)
		ms->cmds[c->i].out = open(ms->cmds[c->i].redirs[c->k].arg, \
			O_CREAT | O_TRUNC | O_WRONLY, 0666);
	else if (ms->cmds[c->i].redirs[c->k].type == D_REDIR_OUT)
		ms->cmds[c->i].out = open(ms->cmds[c->i].redirs[c->k].arg, \
			O_CREAT | O_APPEND | O_WRONLY, 0666);
	else if (ms->cmds[c->i].redirs[c->k].type == REDIR_IN)
	{
		if (open(ms->cmds[c->i].redirs[c->k].arg, O_RDONLY, 0666) != -1)
			ms->cmds[c->i].in = open(ms->cmds[c->i].redirs[c->k].arg, \
				O_RDONLY, 0777);
		else
		{
			ms->cmds[c->i].err = true;
			ft_error_var_start("No such file or directory", \
				ms->cmds[c->i].redirs[c->k].arg, 1);
		}
	}
	else if (ms->cmds[c->i].redirs[c->k].type == HERE_DOC)
		if (!ft_is_heredoc(ms, &ms->cmds[c->i], \
		&ms->cmds[c->i].redirs[c->k], c->i))
			return (false);
	c->k++;
	return (true);
}
