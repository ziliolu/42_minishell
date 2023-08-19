/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_executable.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialves-m <ialves-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 15:10:02 by lpicoli-          #+#    #+#             */
/*   Updated: 2023/08/12 17:41:35 by ialves-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

bool	ft_check_executable_error(t_ms *ms, char *cmd, char *total_path)
{
	if (ms->go_out == -1)
	{
		if (ft_is_absolute_path(cmd))
			ft_free(total_path);
		return (true);
	}
	return (false);
}

bool	ft_is_executable(t_ms *ms, t_command *cmd)
{
	char	*path_w_slash;
	char	*total_path;

	ms->i = 0;
	ms->go_out = 0;
	path_w_slash = NULL;
	total_path = NULL;
	if (cmd->err)
		return (true);
	if (ft_is_absolute_path(cmd->args[0]))
		total_path = ft_strdup(cmd->args[0]);
	while ((ms->paths && ms->paths[ms->i]) || total_path)
	{
		ft_is_executable_while_path(ms, cmd, &path_w_slash, &total_path);
		if (ft_check_executable_error(ms, cmd->args[0], total_path))
			return (false);
		ft_free(total_path);
		ft_free(path_w_slash);
		if (ms->go_out == 1)
			return (true);
		ms->i++;
	}
	return (false);
}
