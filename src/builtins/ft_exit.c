/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpicoli- <lpicoli-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 13:05:23 by lpicoli-          #+#    #+#             */
/*   Updated: 2023/07/25 17:40:34 by lpicoli-         ###   ########.fr       */
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
	if(ms->atoi_tmp == 0 && ft_strcmp(cmd->args[1], "0") != 0)
	{
		ft_free(tmp);
		printf("minishell: exit: %s: numeric argument required\n", cmd->args[1]);
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
