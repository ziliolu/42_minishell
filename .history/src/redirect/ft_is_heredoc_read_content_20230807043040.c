/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_heredoc_read_content.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpicoli- <lpicoli-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 10:01:08 by lpicoli-          #+#    #+#             */
/*   Updated: 2023/08/06 16:23:28 by lpicoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"


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
	ft_signals_ignore();
	waitpid(ms->pid, &ms->status, 0);
	if (WIFSIGNALED(ms->status) && g_exit_status == 0)
		g_exit_status = 128 + WTERMSIG(ms->status);
	else if (WIFEXITED(ms->status))
		g_exit_status = WEXITSTATUS(ms->status);
	cmd->in = h->fd;
	
}

// void	ft_is_heredoc_read_content(t_ms *ms, t_command *cmd, t_heredoc *h)
// {
// 	ms->pid = fork();
// 	if (ms->pid == 0)
// 	{
// 		ft_close_pipes(ms);
// 		while (ft_strcmp(h->read_content, h->eof) != 0)
// 		{
// 			ft_free(h->read_content);
// 			h->read_content = readline(h->prompt);
// 			if (ft_is_ctrld_heredoc(cmd, h) || g_exit_status == 130)
// 				break ;
// 			if (ft_strcmp(h->read_content, h->eof) == 0)
// 				break ;
// 			write(h->fd, h->read_content, ft_strlen(h->read_content));
// 			write(h->fd, "\n", 1);
// 		}
// 		ft_free(h->read_content);
// 		close(h->fd);
// 		open(h->str, O_RDONLY);
// 		exit(g_exit_status);
// 	}
// 	ft_signals_ignore();
// 	//waitpid(0, NULL, 0);
// 	if (waitpid(0, NULL, 0) != -1)
// 	{
// 		if (WIFEXITED(ms->status))
// 			g_exit_status = WEXITSTATUS(ms->status);
// 		else if (WIFSIGNALED(ms->status) && g_exit_status == 0)
// 			g_exit_status = 128 + WTERMSIG(ms->status);
// 		ms->processes--;
// 	}
// }
