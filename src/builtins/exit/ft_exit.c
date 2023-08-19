/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpicoli- <lpicoli-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 13:05:23 by lpicoli-          #+#    #+#             */
/*   Updated: 2023/08/16 14:36:43 by lpicoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

void	ft_exit_local_free(t_ms *ms)
{
	ft_free_env(ms->ms_env);
	ft_free_env(ms->export_list);
	ft_free_array(ms->paths);
	ft_free_array(ms->ms_env_array);
	ft_free_array(ms->ms_argv);
	free(ms->count_args);
	ft_free_elem_list(*ms->lexed_list);
	free(ms->lexed_list);
	free(ms->clean);
	ft_free_env(*ms->vars);
	free(ms->vars);
	ft_free(ms->home_dir);
	ft_free_cmds(ms);
}

void	ft_exit(t_ms *ms, t_command *cmd)
{
	int	status;

	if (cmd->args[1] && ft_exit_validation(ms, cmd))
	{
		status = ft_atoi(cmd->args[1]);
		if (ms->n_pipes == 0)
		{
			printf("exit\n");
			ft_exit_local_free(ms);
			exit(status);
		}
		else
			g_exit_status = ft_atoi(cmd->args[1]);
	}
	else if (!cmd->args[1] && ms->n_pipes == 0)
	{
		printf("exit\n");
		ft_exit_local_free(ms);
		exit (g_exit_status);
	}
}
