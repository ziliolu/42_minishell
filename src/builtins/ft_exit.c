/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpicoli- <lpicoli-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 13:05:23 by lpicoli-          #+#    #+#             */
/*   Updated: 2023/07/26 12:52:12 by lpicoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_exit(t_ms *ms, t_command *cmd)
{
	char	*tmp;
	int		pipes;

	tmp = NULL;
	pipes = ms->n_pipes;
	ms->atoi_tmp = 0;
	tmp = ft_exit_is_cmd_arg(ms, cmd, tmp);
	if (cmd->args[1] && !ft_exit_validation(ms, cmd))
	{
		ft_free(tmp);
		exit(2);
	}
	if (pipes == 0)
	{
		ft_printf("exit\n");
		if (tmp)
		{
			ft_free(tmp);
			exit(ms->atoi_tmp);
		}
		exit(g_exit_status);
	}
	if (tmp)
	{
		ft_free(tmp);
		g_exit_status = ms->atoi_tmp;
	}
}
