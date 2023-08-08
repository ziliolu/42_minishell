/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_heredoc_read_content.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialves-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 10:01:08 by lpicoli-          #+#    #+#             */
/*   Updated: 2023/08/08 04:40:24 by ialves-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	signals_continue(t_ms *ms, t_command *cmd, t_heredoc *h)
{
	ft_signals_ignore();
	waitpid(ms->pid, &ms->status, 0);
	if (WIFSIGNALED(ms->status) && g_exit_status == 0)
		g_exit_status = 128 + WTERMSIG(ms->status);
	else if (WIFEXITED(ms->status))
		g_exit_status = WEXITSTATUS(ms->status);
	cmd->in = h->fd;
}

void	ft_is_heredoc_read_content(t_ms *ms, t_command *cmd, t_heredoc *h)
{
	ms->pid = fork();
	if (ms->pid == 0)
	{
		ft_close_pipes(ms);
		while (ft_strcmp(h->read_content, h->eof) != 0)
		{
			ft_free(h->read_content);
			h->read_content = readline(h->prompt);
			if (ft_is_ctrld_heredoc(cmd, h))
				return ;
			if (ft_strcmp(h->read_content, h->eof) == 0)
			{
				break ;
			}
			write(h->fd, h->read_content, ft_strlen(h->read_content));
			write(h->fd, "\n", 1);
		}
		ft_free(h->read_content);
		close(h->fd);
		open(h->str, O_RDONLY);
		exit(g_exit_status);
	}
	signals_continue(ms, cmd, h);
}
