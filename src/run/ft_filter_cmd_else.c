/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_filter_cmd_else.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpicoli- <lpicoli-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 10:01:08 by lpicoli-          #+#    #+#             */
/*   Updated: 2023/07/30 19:15:14 by lpicoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_filter_cmd_else(t_ms *ms, t_command *cmd)
{
	if (ft_is_valid_env_name(ms, cmd->args[0])
		&& ft_strchr_vars(cmd->args[0], '='))
		ft_add_node_to_list(ms, ms->vars, cmd->args[0]);
	else if (ft_strcmp(cmd->args[0], "export") == 0)
		ft_export(ms, cmd);
	else if (ft_strcmp(cmd->args[0], "unset") == 0)
		ft_unset(ms, cmd);
	else if (ft_strcmp(cmd->args[0], "exit") == 0)
		ft_exit(ms, cmd);
	else if (!ft_is_executable(ms, cmd))
	{
		ft_reset_fd_in_out(ms);
		if (ms->n_pipes != 0)
			g_exit_status = 127;
		if (ft_is_absolute_path(cmd->args[0]) || !ms->paths)
			ft_error_var_start("No such file or directory", cmd->args[0], 2);
		else
		{
			ft_printf("%s: command not found\n", cmd->args[0]);
			g_exit_status = 127;
		}
	}
}
