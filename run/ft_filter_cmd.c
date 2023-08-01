/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_filter_cmd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialves-m <ialves-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 10:01:08 by lpicoli-          #+#    #+#             */
/*   Updated: 2023/07/26 16:25:10 by ialves-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_filter_cmd(t_ms *ms, t_command *cmd)
{
	char	*tmp_list;

	if (!cmd->args[0])
		return ;
	if (ft_strcmp(cmd->args[0], "echo") == 0)
		ft_echo(cmd);
	else if (ft_strcmp(cmd->args[0], "cd") == 0)
		ft_cd(ms, cmd);
	else if (ft_strcmp(cmd->args[0], "env") == 0)
		ft_env(ms, cmd, ms->ms_env);
	else if (ft_strcmp(cmd->args[0], "pwd") == 0)
	{
		tmp_list = ft_return_list_info(ms->ms_env, "PWD");
		printf("%s\n", tmp_list);
		ft_free(tmp_list);
	}
	else
		ft_filter_cmd_else(ms, cmd);
}
