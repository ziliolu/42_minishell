/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpicoli- <lpicoli-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 16:20:30 by lpicoli-          #+#    #+#             */
/*   Updated: 2023/07/26 15:43:19 by lpicoli-         ###   ########.fr       */
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
		ft_free_array(ms->paths);
}
