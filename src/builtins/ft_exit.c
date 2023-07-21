/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialves-m <ialves-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 13:05:23 by lpicoli-          #+#    #+#             */
/*   Updated: 2023/07/21 14:36:444 by ialves-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void ft_exit(t_ms *ms, t_command *cmd)
{
	char	*tmp;
	int		atoi_tmp;
	int		pipes;
	
	tmp = NULL;
	pipes = ms->n_pipes;
	if (cmd->args[1])
	{
		tmp = ft_strdup(cmd->args[1]);
		atoi_tmp = ft_atoi(tmp);
	}	
	ft_free_env(ms);
	ft_free_array(ms->paths);
	ft_free_cmds(ms);
	if(pipes == 0)
	{
		ft_printf("exit\n");
		if (tmp)
		{
			ft_free(tmp);	
			exit(atoi_tmp);
		}
		exit(g_exit_status);
	}
	if(tmp)
	{
		ft_free(tmp);
		g_exit_status = atoi_tmp;
	}
}
