/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_executable.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpicoli- <lpicoli-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 15:10:02 by lpicoli-          #+#    #+#             */
/*   Updated: 2023/06/13 16:01:09 by lpicoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"
#include <unistd.h>

bool ft_is_executable(t_ms *ms)
{
	int i;
	int j;

	i = 0;
	j = 0;
    
    int in;
    int out;

    in = dup(STDIN_FILENO);
    out = dup(STDOUT_FILENO);
    
    int r = open("a.text", O_CREAT | O_RDONLY);
	dup2(r, STDOUT_FILENO);
    
	while(j <= ms->n_pipes)
	{	
		if(ft_is_absolute_path(ms->cmds[j].args[0]))
		{
			if(access(ms->cmds[j].args[0], X_OK) == 0)
			{
				fork();
				execve(ms->cmds[j].args[0], ms->cmds[j].args, ms->system_env);
                dup2(out, STDOUT_FILENO);
				return (true);
			}
			return (false);
		}
		while(ms->paths[i])
		{
			if(access(ft_strjoin(ms->paths[i], ms->cmds[j].args[0]), X_OK) == 0)
			{
				pid_t pid;

				pid = fork();
				if(pid == 0)
					execve(ft_strjoin(ms->paths[i], ms->cmds[j].args[0]), ms->cmds[j].args, ms->system_env);
				wait(&pid);
                dup2(out, STDOUT_FILENO);
				return (true);
			}
			i++;
		}
		j++;
	}
	return (false);
}