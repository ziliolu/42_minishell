/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser_one.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpicoli- <lpicoli-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 14:22:46 by ialves-m          #+#    #+#             */
/*   Updated: 2023/07/19 16:17:22 by lpicoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_ptr_is_in_quotes(t_ms *ms, t_counters *p)
{
	if (p->str)
	{
		if (ms->cmds[p->i].args[p->j])
			ms->cmds[p->i].args[p->j]
				= ft_strjoin(ms->cmds[p->i].args[p->j], p->str);
		else
			ms->cmds[p->i].args[p->j] = p->str;
	}
}

void	ft_is_in_single_quote(t_ms *ms, t_counters *p)
{
	if (p->list->status == IN_DQUOTE)
		p->str = ft_strjoin(p->tmp_str, p->list->data);
	p->list = p->list->next;
	while (p->list->type != SINGLE_QUOTE)
	{
		p->str = ft_strjoin_wo_leaks(p->tmp_str, p->list->data);
		p->tmp_str = ft_strdup(p->str);
		p->list = p->list->next;
	}
	if (p->list->status == IN_DQUOTE)
		p->str = ft_strjoin(p->tmp_str, p->list->data);
	if (p->str)
		ft_ptr_is_in_quotes(ms, p);
	else if (!ms->cmds[p->i].args[p->j])
		ms->cmds[p->i].args[p->j] = "";
	if (p->tmp_str)
		free (p->tmp_str);
}

void	ft_is_in_double_quote_while(t_ms *ms, t_counters *p)
{
	char *tmp_expand;
	
	if (p->list->type == ENV)
	{
		tmp_expand = ft_expand(ms->ms_env, *ms->vars, p->list->data);
		p->str = ft_strjoin_wo_leaks(p->tmp_str, tmp_expand);
		p->tmp_str = ft_strdup(p->str);
		ft_free(tmp_expand);
	}
	else
	{
		p->str = ft_strjoin_wo_leaks(p->tmp_str, p->list->data);
		p->tmp_str = ft_strdup(p->str);
	}
}

void	ft_is_in_double_quote(t_ms *ms, t_counters *p)
{
	if (p->list->status == IN_SQUOTE)
		p->str = ft_strjoin(p->tmp_str, p->list->data);
	p->list = p->list->next;
	while (p->list->type != DOUBLE_QUOTE)
	{
		ft_is_in_double_quote_while(ms, p);
		p->list = p->list->next;
	}
	if (p->list->status == IN_SQUOTE)
		p->str = ft_strjoin(p->tmp_str, p->list->data);
	if (p->str)
		ft_ptr_is_in_quotes(ms, p);
	else if (!ms->cmds[p->i].args[p->j])
		ms->cmds[p->i].args[p->j] = "";
	if (p->tmp_str)
		free (p->tmp_str);
}

void	ft_is_redir_single_quote(t_ms *ms, t_counters *p)
{
	(void) ms;
	if (p->list->status == IN_DQUOTE)
		p->str = ft_strjoin(p->tmp_str, p->list->data);
	p->list = p->list->next;
	while (p->list->type != SINGLE_QUOTE)
	{
		p->str = ft_strjoin_wo_leaks(p->tmp_str, p->list->data);
		p->tmp_str = ft_strdup(p->str);
		p->list = p->list->next;
	}
	if (p->list->status == IN_DQUOTE)
		p->str = ft_strjoin(p->tmp_str, p->list->data);
	if (p->tmp_str)
		free (p->tmp_str);
}
