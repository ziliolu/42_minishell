/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit_validation.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialves-m <ialves-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 13:05:23 by lpicoli-          #+#    #+#             */
/*   Updated: 2023/07/26 07:30:25 by ialves-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

bool	ft_exit_validation(t_ms *ms, t_command *cmd)
{
	int		i;
	long long int	nbr;

	(void) ms;
	i = 0;
	nbr = atoll(cmd->args[1]);
	if (nbr >= LLONG_MIN && nbr <= LLONG_MAX)
	{
		while (cmd->args[1][i] != '\0')
		{
			if (!ft_is_valid_number(cmd->args[1][i++]))
			{
				printf("minishell: exit: %s: numeric argument required\n", cmd->args[1]);
				return (false);
			}
		}
	}
	else
	{
		printf("minishell: exit: %s: numeric argument required\n", cmd->args[1]);
		return (false);
	}
	return (true);
}
