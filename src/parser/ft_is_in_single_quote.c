/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_in_single_quote.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpicoli- <lpicoli-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 12:06:12 by lpicoli-          #+#    #+#             */
/*   Updated: 2023/07/25 00:01:20 by lpicoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_is_in_single_quote(t_ms *ms, t_counters *p)
{
	if (p->list->status == IN_DQUOTE)
	{
		ft_free (p->str);
		p->str = ft_strjoin(p->tmp_str, p->list->data);
	}
	p->list = p->list->next;
	while (p->list->type != SINGLE_QUOTE)
	{
		ft_is_env_in_quotes(p, p->list->data);
		p->list = p->list->next;
	}
	if (p->list->status == IN_DQUOTE)
	{
		ft_free (p->str);
		p->str = ft_strjoin(p->tmp_str, p->list->data);
	}
	if (p->str)
	{
		ft_ptr_is_in_quotes(ms, p);
		free (p->str);
	}
	else if (!ms->cmds[p->i].args[p->j])
		ms->cmds[p->i].args[p->j] = "";
	if (p->tmp_str)
		free (p->tmp_str);
}
