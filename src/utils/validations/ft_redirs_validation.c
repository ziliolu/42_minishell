/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_redirs_validation.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialves-m <ialves-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 00:07:27 by ialves-m          #+#    #+#             */
/*   Updated: 2023/07/24 23:04:45 by ialves-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

bool	ft_redirs_validation(t_ms *ms)
{
	t_val_redir	r;

	r.i = 0;
	r.j = 0;
	r.type = ms->cmds[r.i].redirs[r.j].type;
	r.arg = ms->cmds[r.i].redirs[r.j].arg;
	if (r.type && !r.arg)
		return (false);
	while (ms->cmds[r.i].args)
	{
		r.j = 0;
		if (!ft_redirs_validation_while(ms, &r))
			return (false);
		r.i++;
	}
	return (true);
}
