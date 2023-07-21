/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser_while_dif_null.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpicoli- <lpicoli-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 12:06:12 by lpicoli-          #+#    #+#             */
/*   Updated: 2023/07/21 12:14:08 by lpicoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_parser_while_dif_null(t_ms *ms, t_counters *p, int c)
{
	while (p->list != NULL)
	{
		ft_parser_while_dif_pipe(ms, p, c);
		if (p->list != NULL && p->list->type == PIPE_LINE)
		{
			ms->cmds[p->i].args[p->j] = "|";
			ms->cmds[p->i].type = PIPE_LINE;
			p->list = p->list->next;
		}
		p->i++;
	}
}
