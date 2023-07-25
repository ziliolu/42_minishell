/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpicoli- <lpicoli-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 16:20:30 by lpicoli-          #+#    #+#             */
/*   Updated: 2023/07/25 09:54:00 by lpicoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_unset(t_ms *ms)
{
	int i;

	i = 1; 
	while(ms->cmds->args[i])
	{
		ft_remove_node_list(&ms->ms_env, ms->cmds->args[i]);
		i++;
	}
	if (ft_strcmp(ms->cmds->args[1], "PATH") == 0)
		free (ms->paths);
}
