/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpicoli- <lpicoli-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 16:20:30 by lpicoli-          #+#    #+#             */
/*   Updated: 2023/07/24 23:57:50 by lpicoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_unset(t_ms *ms)
{
	ft_remove_node_list(&ms->ms_env, ms->cmds->args[1]);
	if (ft_strcmp(ms->cmds->args[1], "PATH") == 0)
		free (ms->paths);
}
