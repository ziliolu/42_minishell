/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_executable.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpicoli- <lpicoli-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 15:10:02 by lpicoli-          #+#    #+#             */
/*   Updated: 2023/06/16 14:20:45 by lpicoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"
#include <unistd.h>

// bool ft_is_executable(t_ms *ms)
// {
// 	int i;
// 	int j;
// 	int fd[2];

// 	i = 0;
// 	j = 0;
    
// 	dup2(fd[1], STDOUT_FILENO);
// 	while(j <= ms->n_pipes)
// 	{	
// 		if(ft_is_absolute_path(ms->cmds[j].args[0]))
// 		{
// 			if(access(ms->cmds[j].args[0], X_OK) == 0)
// 			{
// 				fork();
// 				execve(ms->cmds[j].args[0], ms->cmds[j].args, ms->system_env);
// 				return (true);
// 			}
// 			return (false);
// 		}
// 		while(ms->paths[i])
// 		{
// 			if(access(ft_strjoin(ms->paths[i], ms->cmds[j].args[0]), X_OK) == 0)
// 			{
// 				pid_t pid;

// 				pid = fork();
// 				if(pid == 0)
// 				{
// 					if(execve(ft_strjoin(ms->paths[i], ms->cmds[j].args[0]), ms->cmds[j].args, ms->system_env))
// 						printf("everything alright!");
// 					else
// 						printf("error!");
// 				}
// 				wait(&pid);
// 				return (true);
// 			}
// 			i++;
// 		}
// 		j++;
// 	}
// 	return (false);
// }

bool ft_is_executable(t_ms *ms, t_command *cmd)
{
	int i;
	//int j;
	//int fd[2];

	i = 0;
	//j = 0;
    
	//dup2(fd[1], STDOUT_FILENO);
	if(ft_is_absolute_path(cmd->args[0]))
	{
		if(access(cmd->args[0], X_OK) == 0)
		{
			fork();
			execve(cmd->args[0], cmd->args, ms->system_env);
			return (true);
		}
		return (false);
	}
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
			//wait(&pid);
			return (true);
		}
		i++;
	}
	return (false);
}