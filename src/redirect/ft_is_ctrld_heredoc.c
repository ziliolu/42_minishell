/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_ctrld_heredoc.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialves-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 10:01:08 by lpicoli-          #+#    #+#             */
/*   Updated: 2023/08/13 22:47:43 by ialves-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

bool	ft_is_ctrld_heredoc(t_command *cmd, t_heredoc *h)
{
	if (!h->read_content)
	{
		(void) cmd;
		cmd->err = true;
		printf("minishell: warning:");
		printf("here-document delimited by end-of-file (wanted `%s')\n", h->eof);
		return (true);
	}
	return (false);
}
