/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo_is_cmd_arg.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpicoli- <lpicoli-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 21:11:50 by ialves-m          #+#    #+#             */
/*   Updated: 2023/08/01 09:14:16 by lpicoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_join_echo_args(t_command *cmd, t_echo *echo)
{
	if (!echo->tmp)
	{
		echo->str = ft_strdup(cmd->args[echo->i]);
		echo->tmp = ft_strdup(cmd->args[echo->i]);
	}
	else if (echo->i > 1)
	{
		if (echo->tmp)
			free(echo->tmp);
		echo->tmp = ft_strjoin(" ", cmd->args[echo->i]);
		echo->final = ft_strjoin(echo->str, echo->tmp);
		if (echo->str)
			free(echo->str);
		echo->str = ft_strdup(echo->final);
		if (echo->final)
			free(echo->final);
	}
}

void	ft_echo_is_cmd_arg(t_command *cmd, t_echo *echo)
{
	int	j;

	j = 0;
	if (!cmd->args[1])
		return ;
	while (cmd->args[j])
	{
		if (ft_strcmp(cmd->args[echo->i], "-n") == 0)
			echo->i++;
		j++;
	}
	while (cmd->args[echo->i])
	{
		ft_join_echo_args(cmd, echo);
		echo->i++;
	}
}
