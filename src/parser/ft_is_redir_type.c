/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_redir_type.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialves-m <ialves-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 14:22:46 by ialves-m          #+#    #+#             */
/*   Updated: 2023/07/22 14:15:01 by ialves-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_is_redir_type(t_ms *ms, t_counters *p)
{
	ms->cmds[p->i].redirs[p->k].type = p->list->type;
	if (!p->list->next)
	{
		printf("bash: syntax error near unexpected token `newline'\n");
		return ;
	}
	p->list = p->list->next;
	while (p->list->type == WHITE_SPACE)
		p->list = p->list->next;
	if (p->list->type == DOUBLE_QUOTE || p->list->type == SINGLE_QUOTE)
	{
		if (p->list->type == SINGLE_QUOTE)
			ft_is_redir_single_quote(ms, p);
		else if (p->list->type == DOUBLE_QUOTE)
			ft_is_redir_double_quote(ms, p);
		ms->cmds[p->i].redirs[p->k].arg = ft_strdup(p->str);
	}
	else
	{	
		ms->cmds[p->i].redirs[p->k].arg = ft_strdup(p->list->data);
	}
	if (p->j > 1)
		p->j--;
	p->k++;
}
