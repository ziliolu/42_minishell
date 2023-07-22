/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_run_cmds copy 6.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialves-m <ialves-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 10:01:08 by lpicoli-          #+#    #+#             */
/*   Updated: 2023/07/22 21:29:33 by ialves-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_filter_cmd(t_ms *ms, t_command *cmd)
{
	char *tmp_list;

	if (!cmd->args[0])
		return ;
	if (ft_strcmp(cmd->args[0], "echo") == 0)
		ft_echo(cmd);
	else if (ft_strcmp(cmd->args[0], "cd") == 0)
		ft_cd(ms, cmd);
	else if (ft_strcmp(cmd->args[0], "env") == 0)
		ft_env(cmd, ms->ms_env);
	else if (ft_strcmp(cmd->args[0], "pwd") == 0)
	{
		tmp_list = ft_return_list_info(ms->ms_env, "PWD");
		printf("%s\n", tmp_list);
		ft_free(tmp_list);
	}
	else if (ft_strchr_vars(cmd->args[0], '='))
		ft_add_node_to_list(ms, ms->vars, cmd->args[0]);
	else if (ft_strcmp(cmd->args[0], "export") == 0)
		ft_export(ms, cmd);
	else if (ft_strcmp(cmd->args[0], "unset") == 0)
		ft_unset(ms);
	else if (ft_strcmp(cmd->args[0], "exit") == 0)
		ft_exit(ms, cmd);
	else if (!ft_is_executable(ms, cmd))
	{
		ft_reset_fd_in_out(ms);
		if (ft_is_absolute_path(cmd->args[0]))
			ft_error_var_start("No such file or directory", cmd->args[0], 2);
		else
			ft_printf("%s: command not found\n", cmd->args[0]);
		g_exit_status = 127;
	}
}
