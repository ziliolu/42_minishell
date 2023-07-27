/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_redirs_validation_while.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialves-m <ialves-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 00:07:27 by ialves-m          #+#    #+#             */
/*   Updated: 2023/07/24 23:00:23 by ialves-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

bool	ft_redirs_validation_while(t_ms *ms, t_val_redir *r)
{
	while (ms->cmds[r->i].redirs && ms->cmds[r->i].redirs[r->j].type)
	{
		if (ft_is_redir(r->type) && ft_is_arg_redir(r->arg))
		{
			ft_printf("minishell: syntax error near unexpected token `%s'\
			\n", r->arg);
			g_exit_status = 2;
			return (false);
		}
		r->j++;
	}
	return (true);
}
