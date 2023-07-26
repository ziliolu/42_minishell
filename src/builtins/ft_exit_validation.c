/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit_validation.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialves-m <ialves-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 13:05:23 by lpicoli-          #+#    #+#             */
/*   Updated: 2023/07/26 16:45:01 by ialves-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

bool	ft_exit_validation(t_ms *ms, t_command *cmd)
{
	long long int	nbr;

	(void) ms;
	nbr = ft_atoll(cmd->args[1]);
	if ((nbr == 0 && ft_strcmp(cmd->args[1], "0") != 0) || (!ft_is_in_llong_range(cmd->args[1])))
	{
		if (ms->n_pipes == 0)
			ft_printf("exit\n");
		ft_reset_fd_in_out(ms);
		printf("minishell: exit: %s: numeric argument required\n", cmd->args[1]);
		return (false);
	}
	return (true);
}