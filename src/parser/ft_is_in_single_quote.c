/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_in_single_quote.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialves-m <ialves-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 12:06:12 by lpicoli-          #+#    #+#             */
/*   Updated: 2023/07/22 14:18:29 by ialves-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_is_in_single_quote(t_ms *ms, t_counters *p)
{
	if (p->list->status == IN_DQUOTE)
		p->str = ft_strjoin(p->tmp_str, p->list->data);
	p->list = p->list->next;
	while (p->list->type != SINGLE_QUOTE)
	{
		p->str = ft_strdup(p->list->data);
		ft_is_env_in_quotes(p, p->str, p->tmp_str);
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
