/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_executable_while_path.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialves-m <ialves-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 15:10:02 by lpicoli-          #+#    #+#             */
/*   Updated: 2023/08/05 20:59:18 by ialves-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_is_executable_while_path(t_ms *ms, t_command *cmd, \
	char **path_w_slash, char **total_path)
{
	struct stat	buf;

	if (!ms->paths[ms->i])
	{
		ms->go_out = -1;
		return ;
	}
	else if (ms->paths && !ft_is_absolute_path(cmd->args[0]))
	{
		*path_w_slash = ft_strjoin(ms->paths[ms->i], "/");
		*total_path = ft_strjoin(*path_w_slash, cmd->args[0]);
	}
	if (access(*total_path, X_OK) == 0
		&& ft_strcmp(cmd->args[0], "") != 0)
	{
		if (stat(cmd->args[0], &buf) == 0 && S_ISDIR(buf.st_mode))
		{
			ft_error_var_start("Is a directory", cmd->args[0], 126);
			ms->go_out = 1;
			return ;
		}
		ft_start_fork(ms, cmd, total_path);
	}
	else if (ft_is_absolute_path(cmd->args[0]))
		ms->go_out = -1;
}

void	ft_start_fork(t_ms *ms, t_command *cmd, char **total_path)
{
	ft_handle_signals_loop();
	ms->pid = fork();
	ms->processes++;
	if (ms->pid == 0)
	{
		ft_close_pipes(ms);
		execve(*total_path, cmd->args, ms->ms_env_array);
	}
	else
		ms->go_out = 1;
}
