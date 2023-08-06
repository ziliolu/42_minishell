/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_change_standard_in_out.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpicoli- <lpicoli-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 10:01:08 by lpicoli-          #+#    #+#             */
/*   Updated: 2023/08/06 15:13:12 by lpicoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

bool	ft_change_standard_in_out(t_command *cmd)
{
	if (cmd->out != 1)
	{
		if (dup2(cmd->out, STDOUT_FILENO) == -1)
			return (false);
		close(cmd->out);
	}
	if (cmd->in != 0)
	{
		if (dup2(cmd->in, STDIN_FILENO) == -1)
			return (false);
		else
			close(cmd->in);
	}
	return (true);
}
