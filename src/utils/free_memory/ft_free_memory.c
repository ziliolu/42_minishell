/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_memory.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpicoli- <lpicoli-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 11:36:32 by lpicoli-          #+#    #+#             */
/*   Updated: 2023/07/28 18:55:06 by lpicoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

void	ft_free_memory(t_ms *ms)
{
	ft_free_array(ms->paths);
	ft_free_array(ms->ms_env_array);
	ft_free_env(ms->ms_env);
	ft_free_env(ms->export_list);
	if (ms->ms_argv)
		ft_free_array(ms->ms_argv);
	if (ms->cmds)
		ft_free_cmds(ms);
	if (ms->count_args)
		free (ms->count_args);
}
