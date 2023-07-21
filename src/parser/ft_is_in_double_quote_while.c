/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_in_double_quote_while.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpicoli- <lpicoli-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 12:06:12 by lpicoli-          #+#    #+#             */
/*   Updated: 2023/07/21 12:06:58 by lpicoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

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
		ft_free(p->str);
		p->str = ft_strjoin_wo_leaks(p->tmp_str, p->list->data);
		p->tmp_str = ft_strdup(p->str);
	}
}