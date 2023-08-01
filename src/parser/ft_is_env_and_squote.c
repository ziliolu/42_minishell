/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_env_and_squote.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpicoli- <lpicoli-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 12:06:12 by lpicoli-          #+#    #+#             */
/*   Updated: 2023/08/01 12:14:04 by lpicoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_is_env_and_squote(t_ms *ms, t_counters *p)
{
	char	*str_expanded;
	char	*tmp_arg;

	str_expanded = NULL;
	str_expanded = ft_expand(ms->ms_env, *ms->vars, p->list->data);
	if (ms->cmds[p->i].args[p->j] && str_expanded)
	{
		tmp_arg = ft_strdup(ms->cmds[p->i].args[p->j]);
		free(ms->cmds[p->i].args[p->j]);
		ms->cmds[p->i].args[p->j] = ft_strjoin(tmp_arg, str_expanded);
		free(tmp_arg);
	}
	else if (!ms->cmds[p->i].args[p->j] && str_expanded)
		ms->cmds[p->i].args[p->j] = ft_strdup(str_expanded);
	ft_free (str_expanded);
}
