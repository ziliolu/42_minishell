/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser_count_pipes.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialves-m <ialves-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 14:22:46 by ialves-m          #+#    #+#             */
/*   Updated: 2023/08/12 17:17:34 by ialves-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_parser_count_pipes(t_ms *ms, t_counters *p)
{
	while (p->i <= (ms->n_pipes * 2))
	{
		ms->cmds[p->i].args = ft_calloc(ms->count_args[p->i] + 1, \
			sizeof(t_command));
		ms->cmds[p->i].in = 0;
		ms->cmds[p->i].out = 1;
		ms->cmds[p->i].status = -1;
		ms->cmds[p->i].err = false;
		if (!ms->cmds[p->i].args)
			return ;
		p->i++;
	}
}
