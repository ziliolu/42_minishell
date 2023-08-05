/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_change_standard_in_out.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpicoli- <lpicoli-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 10:01:08 by lpicoli-          #+#    #+#             */
/*   Updated: 2023/08/05 16:44:47 by lpicoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

bool	ft_change_standard_in_out(t_command *cmd)
{
	if (cmd->out != 1)
	{
		if (dup2(cmd->out, STDOUT_FILENO) == -1)
		{
			printf("dup error");
			return (false);
		}
		close(cmd->out);
	}
	if (cmd->in != 0)
	{
		if (dup2(cmd->in, STDIN_FILENO) == -1)
		{
			printf("dup error in cmd->in, STDIN_FILENO (in: %d), (STDIN: %d)\n", \
			cmd->in, STDIN_FILENO);
			printf("cmd arg = %s\n", cmd->redirs->arg);
			return (false);
		}
		else
			close(cmd->in);
	}
	return (true);
}
