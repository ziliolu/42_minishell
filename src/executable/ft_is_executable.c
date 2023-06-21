/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_executable.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpicoli- <lpicoli-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 15:10:02 by lpicoli-          #+#    #+#             */
/*   Updated: 2023/06/21 18:18:14 by lpicoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"
#include <unistd.h>


bool ft_is_executable(t_ms *ms, t_command *cmd)
{
	int i;
	int pid;
	//int j;
	//int fd[2];

	i = 0;
	//j = 0;
	// verificar e salvar dups antes de comecar o while
    // int in = dup(STDIN_FILENO);
	// int out = dup(STDOUT_FILENO);
	if(cmd->out != 1)
	{
		if(dup2(cmd->out, STDOUT_FILENO) == -1)
			printf("dup2 error!");
		close(cmd->out);	
	}
	if(cmd->in != 0)
	{
		if(dup2(cmd->in, STDIN_FILENO) == -1)
			printf("dup2 error!");
		close(cmd->in);
	}
	printf("out: %d\n", cmd->out);
	printf("out: %s\n", cmd->args[0]);
	printf("standard: %d\n", STDOUT_FILENO);
	if(ft_is_absolute_path(cmd->args[0]))
	{
		if(access(cmd->args[0], X_OK) == 0)
		{
			pid = fork();
			if (pid == 0)
				execve(cmd->args[0], cmd->args, ms->system_env);
			else
				wait(&pid);
			//return (true);
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

				//decidir se será buitin ou execve para saber se usamos fork ou não
				//nos builtins é preciso dar saida com exit
				pid = fork();
				if(pid == 0)
				{
					printf("entrando no child\n");
					if(execve(ft_strjoin(ms->paths[i], cmd->args[0]), cmd->args, ms->system_env))
						printf("everything alright!");
					else
						printf("error!");
				}
				printf("antes do wait\n");
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