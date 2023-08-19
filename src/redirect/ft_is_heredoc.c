/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_heredoc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialves-m <ialves-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 10:01:08 by lpicoli-          #+#    #+#             */
/*   Updated: 2023/08/12 19:11:54 by ialves-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

bool	ft_is_heredoc(t_ms *ms, t_command *cmd, t_redirect *redir, int i)
{
	t_heredoc	h;
	char		*itoa_tmp;
	char		*tmp;

	itoa_tmp = ft_itoa(i);
	h.prompt = "> ";
	h.eof = ft_strdup(redir->arg);
	tmp = ft_strjoin("heredoc", itoa_tmp);
	free (itoa_tmp);
	h.str = ft_strjoin(tmp, ".tmp");
	h.read_content = ft_calloc(1, sizeof(char));
	ft_signals_heredoc(&h);
	h.fd = open(h.str, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	free (tmp);
	ft_is_heredoc_read_content(ms, cmd, &h);
	ft_handle_signals();
	close(h.fd);
	open(h.str, O_RDONLY, 0444);
	unlink(h.str);
	free (h.str);
	free (h.read_content);
	free (h.eof);
	if (g_exit_status == 130)
		return (false);
	return (true);
}
