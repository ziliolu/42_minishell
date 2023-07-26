/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_redir_double_quote.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialves-m <ialves-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 14:22:46 by ialves-m          #+#    #+#             */
/*   Updated: 2023/07/26 19:12:11 by ialves-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_is_redir_double_quote(t_ms *ms, t_counters *p)
{
	(void) ms;
	if (p->list->status == IN_SQUOTE)
	{
		ft_free(p->str);
		p->str = ft_strjoin(p->tmp_str, p->list->data);
	}
	p->list = p->list->next;
	while (p->list->type != DOUBLE_QUOTE)
	{
		ft_list_type_env(ms, p);
		p->list = p->list->next;
	}
	if (p->list->status == IN_SQUOTE)
	{
		ft_free(p->str);
		p->str = ft_strjoin(p->tmp_str, p->list->data);
	}
	if (p->tmp_str)
		free (p->tmp_str);
}

void	ft_list_type_env(t_ms *ms, t_counters *p)
{
	if (p->list->type == ENV)
	{
		p->str = ft_strjoin_wo_leaks(p->tmp_str,
				ft_expand(ms->ms_env, *ms->vars, p->list->data));
		p->tmp_str = ft_strdup(p->str);
	}
	else
	{
		ft_free(p->str);
		p->str = ft_strjoin_wo_leaks(p->tmp_str, p->list->data);
		ft_free(p->tmp_str);
		p->tmp_str = ft_strdup(p->str);
	}
}
