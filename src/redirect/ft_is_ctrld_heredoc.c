/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_ctrld.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpicoli- <lpicoli-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 10:01:08 by lpicoli-          #+#    #+#             */
/*   Updated: 2023/08/05 16:48:07 by lpicoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

bool	ft_is_ctrld_heredoc(t_command *cmd, t_heredoc *h)
{
	if (!h->read_content)
	{
		cmd->err = true;
		printf("minishell: warning:");
		printf("here-document delimited by end-of-file (wanted `%s')\n", h->eof);
		return (true);
	}
	return (false);
}
