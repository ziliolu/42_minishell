/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export_is_cmd_arg.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialves-m <ialves-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 17:20:33 by lpicoli-          #+#    #+#             */
/*   Updated: 2023/07/26 04:41:27 by ialves-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_export_is_cmd_arg(t_ms *ms, t_command *cmd, int i, int *err)
{
	char	*str;

	if ((cmd->args[i + 1] && (cmd->args[i + 1][0] == '=')) || !ft_is_export_type(cmd->args[i]))
	{
		ft_reset_fd_in_out(ms);
		*err += 1;
		if (!ft_is_export_type(cmd->args[i]))
			str = cmd->args[i];
		else
			str = cmd->args[i + 1];
		if (*err == 1)
			ft_printf("minishell: export: `%s': not a valid identifier\n", str);
		g_exit_status = 1;
		return ;
	}
}
//- [] export var ="cat Makefile | grep >"