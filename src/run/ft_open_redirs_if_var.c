/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_open_redirs_if_var.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialves-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 10:01:08 by lpicoli-          #+#    #+#             */
/*   Updated: 2023/07/22 23:43:49 by ialves-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

bool	ft_open_redirs_if_var(t_ms *ms, t_counters *c, char *tmp_arg)
{
	if (ms->cmds[c->i].redirs[c->k].arg[0] == '$')
	{
		tmp_arg = ft_strtrim(ms->cmds[c->i].redirs[c->k].arg, "$");
		if (!ft_is_already_in_list(tmp_arg, *ms->vars)
			&& !ft_is_already_in_list(tmp_arg, ms->ms_env))
		{
			ft_free(tmp_arg);
			return (true);
		}
		ft_free(ms->cmds[c->i].redirs[c->k].arg);
		if (ft_is_already_in_list(tmp_arg, ms->ms_env))
			ms->cmds[c->i].redirs[c->k].arg = \
			ft_return_list_info(ms->ms_env, tmp_arg);
		else if (ft_is_already_in_list(tmp_arg, *ms->vars))
			ms->cmds[c->i].redirs[c->k].arg = \
			ft_return_list_info(*ms->vars, tmp_arg);
		ft_free(tmp_arg);
	}
	return (false);
}
