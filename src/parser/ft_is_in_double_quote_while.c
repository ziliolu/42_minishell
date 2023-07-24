/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_in_double_quote_while.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialves-m <ialves-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 12:06:12 by lpicoli-          #+#    #+#             */
/*   Updated: 2023/07/24 15:40:555 by ialves-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_is_in_double_quote_while(t_ms *ms, t_counters *p, char *tmp_exp_or_data)
{
	if (p->list->type == ENV)
	{
		tmp_exp_or_data = ft_expand(ms->ms_env, *ms->vars, p->list->data);
		ft_is_env_in_quotes(p, tmp_exp_or_data);
	}
	else
	{
		tmp_exp_or_data = ft_strdup(p->list->data);
		ft_is_env_in_quotes(p, tmp_exp_or_data);
	}
	ft_free(tmp_exp_or_data);
}
