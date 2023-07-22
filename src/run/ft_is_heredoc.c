/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_heredoc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialves-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 10:01:08 by lpicoli-          #+#    #+#             */
/*   Updated: 2023/07/23 00:19:42 by ialves-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_is_heredoc(t_command *cmd, t_redirect *redir)
{
	t_heredoc	h;

	h.prompt = "> ";
	h.eof = redir->arg;
	h.str = ft_calloc(1, sizeof(char));
	h.read_content = ft_calloc(1, sizeof(char));
	h.str = ft_is_heredoc_read_content(cmd, &h);
	h.fd = open("temp.txt", O_WRONLY | O_CREAT | O_EXCL | O_TRUNC, 0600);
	h.fd2 = dup(h.fd);
	write(h.fd2, h.str, ft_strlen(h.str));
	close(h.fd2);
	open("temp.txt", O_RDONLY);
	close(h.fd);
	unlink("temp.txt");
	cmd->in = h.fd2;
}
