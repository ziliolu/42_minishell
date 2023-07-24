/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_cmds_while.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialves-m <ialves-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 11:36:32 by lpicoli-          #+#    #+#             */
/*   Updated: 2023/07/24 21:09:06 by ialves-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

void	ft_free_cmds_while(t_ms *ms, int i, int j, int k)
{
	while (ms->cmds[i].type)
	{
		if (ms->cmds[i].redirs)
		{
			k = 0;
			while (ms->cmds[i].redirs[k].arg)
				free(ms->cmds[i].redirs[k++].arg);
			free (ms->cmds[i].redirs);
		}
		while (ms->cmds[i].args[j])
		{
			if (ms->cmds[i].type != PIPE_LINE)
				if (ms->cmds[i].args[j]
					&& ft_strcmp(ms->cmds[i].args[j], "") != 0)
					free (ms->cmds[i].args[j]);
			j++;
		}
		j = 0;
		if (ms->cmds[i].args)
			free (ms->cmds[i].args);
		i++;
	}
}
