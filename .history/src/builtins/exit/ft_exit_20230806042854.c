/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialves-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 13:05:23 by lpicoli-          #+#    #+#             */
/*   Updated: 2023/08/06 04:28:54 by ialves-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

void	ft_exit(t_ms *ms, t_command *cmd)
{
	if (cmd->args[1] && ft_exit_validation(ms, cmd))
	{
		if (ms->n_pipes == 0)
		{
			printf("exit\n");
			exit(ft_atoi(cmd->args[1]));
		}
		else
			g_exit_status = ft_atoi(cmd->args[1]);
	}
	else if (!cmd->args[1] && ms->n_pipes == 0)
	{
		printf("exit\n");
		exit (g_exit_status);
	}
}
