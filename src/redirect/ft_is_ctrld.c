/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_heredoc_read_content copy 3.c                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialves-m <ialves-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 10:01:08 by lpicoli-          #+#    #+#             */
/*   Updated: 2023/08/01 10:29:36 by ialves-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

bool	ft_is_ctrld(t_command *cmd, t_heredoc *h, char **tmp)
{
	if (!h->read_content)
	{
		cmd->err = true;
		printf("minishell: warning:");
		printf("here-document delimited by end-of-file (wanted `%s')\n", h->eof);
		ft_free(*tmp);
		return (true);
	}
	return (false);
}
