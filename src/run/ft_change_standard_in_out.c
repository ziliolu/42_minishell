/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_change_standard_in_out.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialves-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 10:01:08 by lpicoli-          #+#    #+#             */
/*   Updated: 2023/07/22 23:49:24 by ialves-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

bool	ft_change_standard_in_out(t_command *cmd)
{
	if (cmd->out != 1)
	{
		if (dup2(cmd->out, STDOUT_FILENO) == -1)
		{
			printf("dup2 error!\n");
			return (false);
		}
		close(cmd->out);
	}
	if (cmd->in != 0)
	{
		if (dup2(cmd->in, STDIN_FILENO) == -1)
		{
			printf("dup2 error!\n");
			return (false);
		}
		else
			close(cmd->in);
	}
	return (true);
}
