/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpicoli- <lpicoli-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 15:45:13 by lpicoli-          #+#    #+#             */
/*   Updated: 2023/08/01 09:16:29 by lpicoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

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
		if (cmd->args[1] && ft_strcmp(cmd->args[1], "-n") == 0)
			ft_printf("%s", echo.str);
		else if (cmd->args[1])
			ft_printf("%s\n", echo.str);
	}
	if (echo.str)
		free (echo.str);
	g_exit_status = 0;
}
