/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_executable.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpicoli- <lpicoli-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 15:10:02 by lpicoli-          #+#    #+#             */
/*   Updated: 2023/07/13 16:04:01 by lpicoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

#define LOOP_TIMEOUT 1

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
				int pid;

				ft_handle_signals_loop();
				pid = fork();
				if(pid == 0)
				{
					execve(total_path, cmd->args, ms->ms_env_array);
				}
				// else if(pid > 0)
				// {
				// 	child_pid = waitpid(pid, &status, WNOHANG);
				// 	while(timeout < LOOP_TIMEOUT)
				// 	{
				// 		sleep(1);
				// 		timeout++;
				// 		child_pid = waitpid(pid, &status, WNOHANG);
				// 	}
				// }
				// if(timeout >= LOOP_TIMEOUT)
				// 	return (true);
				//close(ms->cmds[1].fd[0]);
				//close(ms->cmds[1].fd[1]);
				
				// ft_reset_fd_in_out(ms);
				waitpid(pid, &status, 0);
				//ms->cmds->out = 1;
				if(WIFEXITED(status)) //com sucesso
					g_exit_status = WEXITSTATUS(status);		
				else if(WIFSIGNALED(status))
					g_exit_status = 128 + WTERMSIG(status);
				free(total_path);
				free(path_w_slash);
				return (true);
			}
			i++;
			free(total_path);
			free(path_w_slash);
		}
	}
	return (false);
}
