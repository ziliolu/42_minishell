/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export_is_cmd_arg.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpicoli- <lpicoli-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 17:20:33 by lpicoli-          #+#    #+#             */
/*   Updated: 2023/07/24 23:21:17 by lpicoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_export_is_cmd_arg(t_ms *ms, t_command *cmd, int i)
{
	if ((cmd->args[i + 1] && (cmd->args[i + 1][0] == '='))
		|| !ft_is_export_type(cmd->args[i]))
	{
		ft_reset_fd_in_out(ms);
		if (!ft_is_export_type(cmd->args[i]))
			ft_printf("minishell: export: `%s': not a valid identifier\n",
				cmd->args[i]);
		else
			ft_printf("minishell: export: `%s': not a valid identifier\n",
				cmd->args[i + 1]);
		g_exit_status = 1;
		return ;
	}
}
