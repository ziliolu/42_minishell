/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpicoli- <lpicoli-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 17:56:37 by lpicoli-          #+#    #+#             */
/*   Updated: 2023/07/19 10:18:18 by lpicoli-         ###   ########.fr       */
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
		ft_if_redir_dif_pipe(ms, p);
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

void	ft_parser(t_ms *ms, t_elem *list)
{
	int			counter;
	t_counters	p;

	ms->spaces_flag = 0;
	counter = ft_count_tokens(list);
	ms->n_pipes = ft_count_pipes(list);
	ms->cmds = ft_calloc(ms->n_pipes * 2 + 2, sizeof(t_command));
	p.i = 0;
	p.j = 0;
	p.k = 0;
	p.list = list;
	if (!ms->cmds)
		return ;
	ft_parser_count_pipes(ms, &p);
	p.tmp_str = NULL;
	p.i = 0;
	ft_parser_while_dif_null(ms, &p, counter);
}

bool	ft_is_not_redir(enum e_token type)
{
	if (type != REDIR_IN && type != REDIR_OUT
		&& type != HERE_DOC && type != D_REDIR_OUT)
		return (true);
	return (false);
}
