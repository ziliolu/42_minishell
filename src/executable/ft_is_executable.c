/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_executable.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialves-m <ialves-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 15:10:02 by lpicoli-          #+#    #+#             */
/*   Updated: 2023/07/14 11:18:13 by ialves-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

bool ft_is_executable(t_ms *ms, t_command *cmd)
{
	int i;
	int pid;
	int status;
	// int child_pid;
	// int timeout;
	
	i = 0;
	//timeout = 0;
	if(ft_is_absolute_path(cmd->args[0]))
	{
		if(access(cmd->args[0], X_OK) == 0)
		{
			pid = fork();
			if (pid == 0)
				execve(cmd->args[0], cmd->args, ms->ms_env_array);
			waitpid(pid, &status, 0);
			if(WIFEXITED(status))
				g_exit_status = WEXITSTATUS(status);	
			else if(WIFSIGNALED(status))
				g_exit_status = WTERMSIG(status);
			return (true);
		}
		return (false);
	}
	else
	{
		while(ms->paths[i])
		{
			char *path_w_slash = ft_strjoin(ms->paths[i], "/");
			char *total_path = ft_strjoin(path_w_slash, cmd->args[0]);
			if (access(total_path, X_OK) == 0)
			{
				ft_handle_signals_loop();
				cmd->pid = fork();
				if(cmd->pid == 0)
				{
					execve(total_path, cmd->args, ms->ms_env_array);
				}
				else
				{
					free(total_path);
					free(path_w_slash);
					return (true);
				}
			}
			i++;
			free(total_path);
			free(path_w_slash);
		}
	}
	return (false);
}
