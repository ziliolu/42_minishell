/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo_is_cmd_arg.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialves-m <ialves-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 21:11:50 by ialves-m          #+#    #+#             */
/*   Updated: 2023/07/21 21:17:46 by ialves-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_echo_is_cmd_arg(t_command *cmd, t_echo *echo)
{
	if (cmd->args[1] && ft_strcmp(cmd->args[1], "-n") == 0)
		echo->i++;
	while (cmd->args[echo->i])
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
		echo->i++;
	}
}
