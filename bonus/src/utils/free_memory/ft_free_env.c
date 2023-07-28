/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpicoli- <lpicoli-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 11:36:32 by lpicoli-          #+#    #+#             */
/*   Updated: 2023/07/28 19:51:12 by lpicoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

void	ft_free_env(t_ms *ms)
{
	t_lst	*list;

	list = NULL;
	list = ms->ms_env;
	while (ms->ms_env)
	{
		if (ms->ms_env)
		{
			list = ms->ms_env->next;
			free (ms->ms_env->name);
			free (ms->ms_env->info);
			free (ms->ms_env->full_info);
			free (ms->ms_env);
		}
		ms->ms_env = list;
	}
	if (list)
		free (list);
}
