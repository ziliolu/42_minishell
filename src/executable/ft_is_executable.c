/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_executable.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialves-m <ialves-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 15:10:02 by lpicoli-          #+#    #+#             */
/*   Updated: 2023/07/18 17:51:01 by ialves-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

bool ft_is_executable(t_ms *ms, t_command *cmd)
{
	int i;
	char *path_w_slash;
	char *total_path;

	i = 0;
	path_w_slash = NULL;
	total_path = NULL;
	if(cmd->err)
		return (true);
	if(ft_is_absolute_path(cmd->args[0]))
		total_path = ft_strdup(cmd->args[0]);
	while(ms->paths[i])
	{
		if (!ft_is_absolute_path(cmd->args[0]))
		{
			path_w_slash = ft_strjoin(ms->paths[i], "/");
			total_path = ft_strjoin(path_w_slash, cmd->args[0]);
		}
		if (access(total_path, X_OK) == 0)
		{
			ft_handle_signals_loop();
			ms->pid = fork();
			ms->processes++;
			if(ms->pid == 0)
			{
				ft_close_pipes(ms);
				execve(total_path, cmd->args, ms->ms_env_array);
			}
			else
			{
				ft_free(total_path);
				ft_free(path_w_slash);
				return (true);
			}
		}
		ft_free(total_path);
		ft_free(path_w_slash);
		i++;
	}
	return (false);
}

