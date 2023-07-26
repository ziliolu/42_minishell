/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit_validation.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialves-m <ialves-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 13:05:23 by lpicoli-          #+#    #+#             */
/*   Updated: 2023/07/26 12:30:25 by ialves-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

bool	ft_exit_validation(t_ms *ms, t_command *cmd)
{
	//int		i;
	long long int	nbr;

	(void) ms;
	//i = 0;

	nbr = ft_atoll(cmd->args[1]);
	if (nbr >= LLONG_MIN && nbr <= LLONG_MAX)
	{
		if (nbr == 0 && ft_strcmp(cmd->args[1], "0") != 0)
		{
			printf("minishell: exit: %s: numeric argument required\n", cmd->args[1]);
			return (false);
		}
	}
	else
	{
		printf("minishell: exit: %s: numeric argument required\n", cmd->args[1]);
		return (false);
	}
	return (true);
}
// LLONG_MIN -9223372036854775808
// LLONG_MAX 9223372036854775807
// ULLONG MAX 18446744073709551615