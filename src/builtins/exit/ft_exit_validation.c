/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit_validation.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialves-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 13:05:23 by lpicoli-          #+#    #+#             */
/*   Updated: 2023/08/12 07:40:09 by ialves-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

bool	ft_cmd_has_pipes(t_ms *ms, t_command *cmd)
{
	if (ms->n_pipes == 0)
	{
		printf("exit\n");
		printf("minishell: exit: %s: numeric argument required\n", \
		cmd->args[1]);
		ft_exit_local_free(ms);
		exit (2);
	}
	else
	{
		printf("minishell: exit: %s: numeric argument required\n", \
		cmd->args[1]);
		g_exit_status = 2;
	}
	return (false);
}

int	ft_count_args_actual_cmd(t_command *cmd)
{
	int	i;

	i = 0;
	while (cmd->args[i])
		i++;
	return (i);
}

bool	ft_exit_validation(t_ms *ms, t_command *cmd)
{
	long long int	nbr;

	nbr = ft_atoll(cmd->args[1]);
	ft_reset_fd_in_out(ms);
	if ((nbr == 0 && ft_strcmp(cmd->args[1], "0") != 0)
		|| !ft_is_in_llong_range(cmd->args[1]))
		return (ft_cmd_has_pipes(ms, cmd));
	else
	{
		if (ft_count_args_actual_cmd(cmd) > 2)
		{
			if (ms->n_pipes == 0)
				printf("exit\n");
			printf("minishell: exit: too many arguments\n");
			return (false);
		}
	}
	return (true);
}
