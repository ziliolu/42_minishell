/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_executable.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialves-m <ialves-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 15:10:02 by lpicoli-          #+#    #+#             */
/*   Updated: 2023/06/29 15:44:17 by ialves-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

bool ft_is_executable(t_ms *ms, t_command *cmd)
{
	int i;
	int pid;
	int status;
	char **ms_env_array;

	ms_env_array = ft_env_to_array(ms);

	i = 0;
	if(cmd->out != 1)
	{
		if(dup2(cmd->out, STDOUT_FILENO) == -1)
		{
			printf("dup2 error!\n");
			printf("fd:%d\n", cmd->out);
		}
		close(cmd->out);
	}
	
	if(cmd->in != 0)
	{
		if(dup2(cmd->in, STDIN_FILENO) == -1)
			printf("dup2 error!\n");
		close(cmd->in);
	}

	if(ft_is_absolute_path(cmd->args[0]))
	{
		if(access(cmd->args[0], X_OK) == 0)
		{
			pid = fork();
			if (pid == 0)
				execve(cmd->args[0], cmd->args, ms_env_array);
			else
				wait(&pid);
		}
		return (false);
	}
	else
	{
		while(ms->paths[i])
		{
			if (access(ft_strjoin(ft_strjoin(ms->paths[i], "/"), cmd->args[0]), X_OK) == 0)
			{
				int pid;

				pid = fork();
				if(pid == 0)
				{
					execve(ft_strjoin(ft_strjoin(ms->paths[i], "/"), cmd->args[0]), cmd->args, ms_env_array);
				}
				waitpid(pid, &status, 0);
				if(WIFEXITED(status))
					g_exit_status = WEXITSTATUS(status);	
				else if(WIFSIGNALED(status))
					g_exit_status = WTERMSIG(status);	
				dup2(ms->std_out, STDOUT_FILENO);
				dup2(ms->std_in, STDIN_FILENO);
				return (true);
			}
			i++;
		}
	}
	return (false);
}
