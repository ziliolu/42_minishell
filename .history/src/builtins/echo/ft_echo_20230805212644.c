/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialves-m <ialves-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 15:45:13 by lpicoli-          #+#    #+#             */
/*   Updated: 2023/08/05 21:26:44 by ialves-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

bool	echo_is_n(char *arg)
{
	int	i;

	i = 0;
	if (arg[i++] == '-')
	{
		if (arg[i++] == 'n')
		{
			while (arg[i])
			{
				if (arg[i] == 'n')
					i++;
				else
					return (false);
			}
		}
	}
	else
		return (false);
	return (true);
}

void	ft_echo(t_command *cmd)
{
	t_echo	echo;

	echo.i = 1;
	echo.str = NULL;
	echo.tmp = NULL;
	ft_echo_is_cmd_arg(cmd, &echo);
	if (echo.tmp)
		free(echo.tmp);
	if (!cmd->args[1])
		ft_printf("\n");
	else if (echo.str)
	{
		if (cmd->args[1] && echo_is_n(cmd->args[1]))
			ft_printf("%s", echo.str);
		else if (cmd->args[1])
			ft_printf("%s\n", echo.str);
	}
	if (echo.str)
		free (echo.str);
	g_exit_status = 0;
}
