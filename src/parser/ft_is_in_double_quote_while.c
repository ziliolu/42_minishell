/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_in_double_quote_while.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialves-m <ialves-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 12:06:12 by lpicoli-          #+#    #+#             */
/*   Updated: 2023/07/22 14:53:52 by ialves-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_is_in_double_quote_while(t_ms *ms, t_counters *p)
{
	char	*tmp_expand;

	tmp_expand = NULL;
	if (p->list->type == ENV)
	{
		tmp_expand = ft_expand(ms->ms_env, *ms->vars, p->list->data);
		ft_is_env_in_quotes(p, tmp_expand, p->tmp_str);
		ft_free(tmp_expand);
	}
	else
	{
		p->str = ft_strdup(p->list->data);
		ft_is_env_in_quotes(p, p->str, p->tmp_str);
	}
}
