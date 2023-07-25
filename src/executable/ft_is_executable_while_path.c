/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_executable_while_path.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialves-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 15:10:02 by lpicoli-          #+#    #+#             */
/*   Updated: 2023/07/25 15:08:02 by ialves-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_is_executable_while_path(t_ms *ms, t_command *cmd, \
	char **path_w_slash, char **total_path)
{
	struct stat buf;
	if (!ft_is_absolute_path(cmd->args[0]))
	{
		*path_w_slash = ft_strjoin(ms->paths[ms->i], "/");
		*total_path = ft_strjoin(*path_w_slash, cmd->args[0]);
	}
	if (access(*total_path, X_OK) == 0)
	{
		if (stat(*total_path, &buf) == 0)
		{
			if (S_ISDIR(buf.st_mode))
			{
				ft_error_var_start("Is a directory", *total_path, 126);
				ms->go_out = 1;
				ft_free(*path_w_slash);
				ft_free(*total_path);
				return ;	
			}
		}
		ft_handle_signals_loop();
		ms->pid = fork();
		ms->processes++;
		if (ms->pid == 0)
		{
			ft_close_pipes(ms);
			execve(*total_path, cmd->args, ms->ms_env_array);
		}
		else
		{
			ft_free(*path_w_slash);
			ft_free(*total_path);
			ms->go_out = 1;
		}
	}
}
