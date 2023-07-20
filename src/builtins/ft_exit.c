/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpicoli- <lpicoli-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 13:05:23 by lpicoli-          #+#    #+#             */
/*   Updated: 2023/07/20 11:43:12 by lpicoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void ft_exit(t_ms *ms, t_command *cmd)
{
	if(ms->n_pipes == 0)
	{
		ft_printf("exit\n");
		ft_free_env(ms);
		ft_free_array(ms->paths);
		if (ms->cmds[0].args[1])
			exit(ft_atoi(ms->cmds[0].args[1]));
		exit(g_exit_status);
	}
	if(cmd->args[1])
		g_exit_status = ft_atoi(cmd->args[1]);
	//wait(0);
	//exit(g_exit_status);
}
