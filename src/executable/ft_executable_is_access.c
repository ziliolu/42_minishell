/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_executable_is_access.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialves-m <ialves-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 15:10:02 by lpicoli-          #+#    #+#             */
/*   Updated: 2023/07/21 22:41:16 by ialves-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

// bool	ft_executable_is_access(t_ms *ms, t_command *cmd, 
// 	char *total_path, char *path_w_slash)
// {
// 	if (access(total_path, X_OK) == 0)
// 	{
// 		ft_handle_signals_loop();
// 		ms->pid = fork();
// 		ms->processes++;
// 		if (ms->pid == 0)
// 		{
// 			ft_close_pipes(ms);
// 			execve(total_path, cmd->args, ms->ms_env_array);
// 		}
// 		else
// 		{
// 			ft_free(total_path);
// 			ft_free(path_w_slash);
// 			return (true);
// 		}
// 		// return (true);
// 	}
// 	// return (false);
// }
