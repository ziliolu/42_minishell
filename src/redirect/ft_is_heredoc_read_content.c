/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_heredoc_read_content.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialves-m <ialves-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 10:01:08 by lpicoli-          #+#    #+#             */
/*   Updated: 2023/08/16 14:54:30 by ialves-m         ###   ########.fr       */
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

void	ft_exit_heredoc_free(t_ms *ms)
{
	ft_free_env(ms->ms_env);
	ft_free_env(ms->export_list);
	ft_free_array(ms->paths);
	ft_free_array(ms->ms_env_array);
	ft_free_array(ms->ms_argv);
	free(ms->count_args);
	ft_free_elem_list(*ms->lexed_list);
	free(ms->lexed_list);
	if (ms->clean)
		free(ms->clean);
	ft_free_env(*ms->vars);
	free(ms->vars);
	ft_free(ms->home_dir);
	ft_free_cmds(ms);
}

void	ft_free_from_heredoc_signal(t_ms *ms, t_heredoc *h)
{
	h->ms = &*ms;
}

void	ft_is_heredoc_read_content(t_ms *ms, t_command *cmd, t_heredoc *h)
{
	ms->pid = fork();
	if (ms->pid == 0)
	{
		ft_free_from_heredoc_signal(ms, h);
		ft_close_pipes(ms);
		while (ft_strcmp(h->read_content, h->eof) != 0)
		{
			ft_free(h->read_content);
			h->read_content = readline(h->prompt);
			if (ft_is_ctrld_heredoc(cmd, h))
				break ;
			if (ft_strcmp(h->read_content, h->eof) == 0)
				break ;
			write(h->fd, h->read_content, ft_strlen(h->read_content));
			write(h->fd, "\n", 1);
		}
		ft_exit_heredoc_free(ms);
		ft_free(h->read_content);
		close(h->fd);
		open(h->str, O_RDONLY);
		ft_free(h->eof);
		ft_free(h->str);
		exit(g_exit_status);
	}
	signals_continue(ms, cmd, h);
}
