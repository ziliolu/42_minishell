/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export_is_cmd_arg.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpicoli- <lpicoli-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 17:20:33 by lpicoli-          #+#    #+#             */
/*   Updated: 2023/08/16 11:03:02 by lpicoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

void	ft_export_is_cmd_arg(t_ms *ms, t_command *cmd, int i)
{
	if (!ft_is_valid_env_name(ms, cmd->args[i]))
	{
		ft_reset_fd_in_out(ms);
		ft_printf("minishell: export: `%s': not a valid identifier\n", \
		cmd->args[i]);
		g_exit_status = 1;
	}
	else if (ft_is_valid_env_name(ms, cmd->args[i])
		&& ft_strchr_vars(cmd->args[i], '=') == 0)
	{
		if (!ft_is_already_in_list(cmd->args[i], ms->export_list) \
		&& ms->n_pipes == 0)
			ft_add_export_node(&ms->export_list, cmd->args[i]);
	}
}
