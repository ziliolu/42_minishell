/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_heredoc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpicoli- <lpicoli-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 10:01:08 by lpicoli-          #+#    #+#             */
/*   Updated: 2023/08/05 16:55:44 by lpicoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_is_heredoc(t_ms *ms, t_command *cmd, t_redirect *redir, int i)
{
	t_heredoc	h;

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
	ft_handle_signals();
}
