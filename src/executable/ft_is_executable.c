/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_executable.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpicoli- <lpicoli-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 15:10:02 by lpicoli-          #+#    #+#             */
/*   Updated: 2023/06/22 12:21:09 by lpicoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

bool ft_is_executable(t_ms *ms, t_command *cmd)
{
	int i;
	int pid;

	i = 0;
	if(cmd->out != 1)
	{
		if(dup2(cmd->out, STDOUT_FILENO) == -1)
			printf("dup2 error!");
		close(cmd->out); // cmd.out + pipe	
	}
	
	if(cmd->in != 0)
	{
		if(dup2(cmd->in, STDIN_FILENO) == -1)
			printf("dup2 error!");
		close(cmd->in);
	}

	if(ft_is_absolute_path(cmd->args[0]))
	{
		if(access(cmd->args[0], X_OK) == 0)
		{
			pid = fork();
			if (pid == 0)
				execve(cmd->args[0], cmd->args, ms->system_env);
			else
				wait(&pid);
		}
		return (false);
	}
	else
	{
		while(ms->paths[i])
		{
			if(access(ft_strjoin(ms->paths[i], cmd->args[0]), X_OK) == 0)
			{
				pid_t pid;

				pid = fork();
				if(pid == 0)
				{
					if(execve(ft_strjoin(ms->paths[i], cmd->args[0]), cmd->args, ms->system_env))
						printf("everything alright!");
					else
						printf("error!");
				}

				wait(&pid);
				// while(waitpid(0, NULL, 0) > 0)
                // 	continue;
				dup2(ms->std_out, STDOUT_FILENO);
				dup2(ms->std_in, STDIN_FILENO);
				return (true);
			}
			i++;
		}
	}
	return (false);
}
