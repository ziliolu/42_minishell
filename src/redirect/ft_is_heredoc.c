/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_heredoc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpicoli- <lpicoli-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 10:01:08 by lpicoli-          #+#    #+#             */
/*   Updated: 2023/07/31 17:40:13 by lpicoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_is_heredoc(t_ms *ms, t_command *cmd, t_redirect *redir)
{
	t_heredoc	h;

	h.prompt = "> ";
	h.eof = redir->arg;
	h.str = ft_calloc(1, sizeof(char));
	h.read_content = ft_calloc(1, sizeof(char));
	ft_signals_heredoc();
	h.str = ft_is_heredoc_read_content(ms, cmd, &h);
	h.fd = open("temp.txt", O_WRONLY | O_CREAT | O_TRUNC, 0666);
	write(h.fd, h.str, ft_strlen(h.str));
	write(h.fd, "\n", 1);
	ft_free(h.str);
	close(h.fd);
	cmd->in = h.fd;
	ft_signals_ignore();
	if(ms->pid == 0)
		exit(0);
	waitpid(0, NULL, 0);
	ft_handle_signals();
	open("temp.txt", O_RDONLY);
}