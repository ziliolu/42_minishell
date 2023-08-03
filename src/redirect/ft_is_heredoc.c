/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_heredoc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpicoli- <lpicoli-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 10:01:08 by lpicoli-          #+#    #+#             */
/*   Updated: 2023/08/03 17:51:23 by lpicoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"


void	ft_is_heredoc(t_ms *ms, t_command *cmd, t_redirect *redir, int i)
{
	t_heredoc	h;
	//char		*fd_name;

	h.prompt = "> ";
	h.eof = redir->arg;
	h.str = ft_strjoin("heredoc", ft_itoa(i));
	h.read_content = ft_calloc(1, sizeof(char));
	ft_signals_heredoc();
	h.fd = open(h.str, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	ft_is_heredoc_read_content(ms, cmd, &h);
	ft_handle_signals();
	close(h.fd);
	open(h.str, O_RDONLY);
	//cmd->in = h.fd;
	ft_handle_signals();
}

// void	ft_is_heredoc(t_ms *ms, t_command *cmd, t_redirect *redir)
// {
// 	t_heredoc	h;

// 	h.prompt = "> ";
// 	h.eof = redir->arg;
// 	h.str = NULL;
// 	h.read_content = ft_calloc(1, sizeof(char));
// 	if (ms->std_in > STDIN_FILENO)
// 		close(ms->std_in);
// 	ft_signals_heredoc();
// 	ft_is_heredoc_read_content(ms, cmd, &h);
// 	ft_handle_signals();
// 	open(HEREDOC, O_RDONLY);
// 	cmd->in = h.fd;
// 	printf("file no: %d", cmd->in);
// 	printf("file out: %d", cmd->out);
// 	// h.fd = open(HEREDOC, O_WRONLY | O_CREAT | O_TRUNC, 0666);
// 	// if(h.str)
// 	// 	write(h.fd, h.str, ft_strlen(h.str));
// 	// write(h.fd, "\n", 1);
// 	// ft_free(h.str);
// 	// cmd->in = h.fd;
// 	// close(h.fd);
// 	//unlink(HEREDOC);
// 	//cmd->in = h.fd;
// 	ft_handle_signals();
// 	// if(ms->pid == 0)
// 	// 	exit(0);
// 	//waitpid(0, NULL, 0);
// }
