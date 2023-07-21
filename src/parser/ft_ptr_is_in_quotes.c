/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptr_is_in_quotes.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpicoli- <lpicoli-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 14:22:46 by ialves-m          #+#    #+#             */
/*   Updated: 2023/07/21 12:07:52 by lpicoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_ptr_is_in_quotes(t_ms *ms, t_counters *p)
{
	char *tmp_arg;
	if (p->str)
	{
		if (ms->cmds[p->i].args[p->j])
		{
			tmp_arg = ft_strdup(ms->cmds[p->i].args[p->j]);
			ft_free(ms->cmds[p->i].args[p->j]);
			ms->cmds[p->i].args[p->j]= ft_strjoin(tmp_arg, p->str);
			ft_free(tmp_arg);
		}
		else
			ms->cmds[p->i].args[p->j] = ft_strdup(p->str);
	}
	ft_free(p->str);
}
