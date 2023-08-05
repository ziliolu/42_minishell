/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_heredoc_read_content.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpicoli- <lpicoli-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 10:01:08 by lpicoli-          #+#    #+#             */
/*   Updated: 2023/08/05 16:55:52 by lpicoli-         ###   ########.fr       */
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
			if (ft_is_ctrld_heredoc(cmd, h) || g_exit_status == 130)
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
	waitpid(0, NULL, 0);
	cmd->in = h->fd;
}
