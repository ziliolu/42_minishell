/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser_while_dif_pipe.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialves-m <ialves-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 14:22:46 by ialves-m          #+#    #+#             */
/*   Updated: 2023/07/22 14:49:13 by ialves-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_parser_while_dif_pipe(t_ms *ms, t_counters *p, int c)
{
	int	space;

	p->j = 0;
	p->k = 0;
	ms->cmds[p->i].redirs = ft_calloc(c, sizeof(t_redirect));
	ms->cmds[p->i].type = CMD;
	while (p->list != NULL && p->list->type != PIPE_LINE)
	{
		ft_parser_is(ms, p);
		p->list = p->list->next;
		space = 0;
		if (p->list && p->list->type == WHITE_SPACE)
		{
			while (p->list && p->list->type == WHITE_SPACE)
				p->list = p->list->next;
			space++;
			ms->spaces_flag++;
		}
		if ((ms->cmds[p->i].args[p->j]
				|| ft_strcmp(ms->cmds[p->i].args[p->j], "") == 0) && space != 0)
			p->j++;
	}
	p->i++;
	p->j = 0;
}
