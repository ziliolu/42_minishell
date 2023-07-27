/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptr_is_in_quotes.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialves-m <ialves-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 14:22:46 by ialves-m          #+#    #+#             */
/*   Updated: 2023/07/24 16:47:50 by ialves-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_ptr_is_in_quotes(t_ms *ms, t_counters *p)
{
	char	*tmp_arg;

	if (ms->cmds[p->i].args[p->j])
	{
		tmp_arg = ft_strdup(ms->cmds[p->i].args[p->j]);
		ft_free(ms->cmds[p->i].args[p->j]);
		ms->cmds[p->i].args[p->j] = ft_strjoin(tmp_arg, p->str);
		ft_free(tmp_arg);
	}
	else
		ms->cmds[p->i].args[p->j] = ft_strdup(p->str);
}
