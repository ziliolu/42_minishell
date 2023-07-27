/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_in_double_quote_while.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpicoli- <lpicoli-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 00:00:26 by lpicoli-          #+#    #+#             */
/*   Updated: 2023/07/25 00:00:27 by lpicoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_is_in_double_quote_while(t_ms *ms, t_counters *p, char *data)
{
	if (p->list->type == ENV)
	{
		data = ft_expand(ms->ms_env, *ms->vars, p->list->data);
		ft_is_env_in_quotes(p, data);
	}
	else
	{
		data = ft_strdup(p->list->data);
		ft_is_env_in_quotes(p, data);
	}
	ft_free(data);
}
