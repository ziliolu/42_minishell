/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialves-m <ialves-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 16:20:30 by lpicoli-          #+#    #+#             */
/*   Updated: 2023/07/14 11:33:20 by ialves-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void ft_unset(t_ms *ms)
{
    if(!ms->cmds->args[1])
    {
        ft_error(ms, "unset: `': not a valid identifier", NULL);
        return ;
    }
    if(!ft_strchr_vars(ms->cmds->args[1], '='))
	{
        ft_remove_node_list(&ms->ms_env, ms->cmds->args[1]);
		if (ft_strcmp(ms->cmds->args[1], "PATH") == 0)
			free (ms->paths);
	}
}