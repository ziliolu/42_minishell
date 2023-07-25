/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialves-m <ialves-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 16:20:30 by lpicoli-          #+#    #+#             */
/*   Updated: 2023/07/25 12:17:17 by ialves-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_unset(t_ms *ms, t_command *cmd)
{
	int	i;

	i = 1;
	while (cmd->args[i])
	{
		ft_remove_node_list(&ms->ms_env, cmd->args[i], cmd);
		i++;
	}
	if (ft_strcmp(cmd->args[1], "PATH") == 0)
		free (ms->paths);
}
