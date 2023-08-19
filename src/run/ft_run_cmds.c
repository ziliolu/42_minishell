/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_run_cmds.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpicoli- <lpicoli-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 10:01:08 by lpicoli-          #+#    #+#             */
/*   Updated: 2023/08/16 12:47:52 by lpicoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_run_cmds(t_ms *ms)
{
	t_counters	*c;

	c = ft_calloc(1, sizeof(t_counters));
	ms->clean = c;
	ft_init_pipes(ms);
	while (ms->cmds[c->i].type)
	{
		c->k = 0;
		if (!ft_open_redirs(ms, c))
		{
			ft_free_counters(c);
			return ;
		}
		ft_connect_pipes(ms, c);
		if (ms->cmds[c->i].type != PIPE_LINE)
		{
			if (ft_change_standard_in_out(&ms->cmds[c->i]))
			{
				ft_filter_cmd(ms, &ms->cmds[c->i]);
				ft_reset_fd_in_out(ms);
			}
		}
		c->i++;
	}
	ft_free_counters(c);
}
