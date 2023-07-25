/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_redir_double_quote.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpicoli- <lpicoli-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 14:22:46 by ialves-m          #+#    #+#             */
/*   Updated: 2023/07/25 16:56:29 by lpicoli-         ###   ########.fr       */
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
