/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export_is_cmd_arg.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpicoli- <lpicoli-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 17:20:33 by lpicoli-          #+#    #+#             */
/*   Updated: 2023/07/28 17:17:04 by lpicoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_export_is_cmd_arg(t_ms *ms, t_command *cmd, int i, int *err)
{
	char	*str;

	if ((cmd->args[i + 1] && (cmd->args[i + 1][0] == '='))
		|| !ft_is_export_type(cmd->args[i]))
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
	else if(!cmd->args[2] && ft_is_valid_env_name(ms, cmd->args[1]) && ft_strchr_vars(cmd->args[i], '=') == 0)
	{
		if(!ft_is_already_in_list(cmd->args[1], ms->export_list))
			ft_add_export_node(&ms->export_list, ft_strdup(cmd->args[1]));
	}
}
