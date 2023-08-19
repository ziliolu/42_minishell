/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpicoli- <lpicoli-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 16:20:30 by lpicoli-          #+#    #+#             */
/*   Updated: 2023/08/16 11:01:58 by lpicoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

bool	ft_is_valid_identifier(t_ms *ms, t_command *cmd, int i)
{
	char	*str;
	int		err;

	err = 0;
	if ((cmd->args[i + 1] && (cmd->args[i + 1][0] == '='))
			|| !ft_is_export_type(cmd->args[i]))
	{
		ft_reset_fd_in_out(ms);
		err += 1;
		if (!ft_is_export_type(cmd->args[i]))
			str = cmd->args[i];
		else
			str = cmd->args[i + 1];
		if (err == 1)
			ft_printf("minishell: export: `%s': not a valid identifier\n", str);
		g_exit_status = 1;
		return (false);
	}
	return (true);
}

void	ft_verify_if_is_unset_env_vars(t_ms *ms, t_command *cmd, int i)
{
	if (ft_strcmp(cmd->args[i], "PATH") == 0)
	{
		ft_free_array(ms->paths);
		ms->paths = NULL;
	}
	else if (ft_strcmp(cmd->args[i], "HOME") == 0)
	{
		ft_free(ms->home_dir);
		ms->home_dir = ft_return_list_info(ms->ms_env, "HOME");
	}
}

void	ft_unset(t_ms *ms, t_command *cmd)
{
	int	i;

	i = 1;
	while (cmd->args[i])
	{
		ft_verify_if_is_unset_env_vars(ms, cmd, i);
		if ((cmd->args[i] && ft_strchr(cmd->args[i], '='))
			|| !ft_is_valid_env_name(ms, cmd->args[i]))
		{
			ft_reset_fd_in_out(ms);
			printf("minishell: unset: `%s': not a valid identifier\n", \
			cmd->args[i]);
			g_exit_status = 1;
		}
		if (ft_is_valid_env_name(ms, cmd->args[i]) && ms->n_pipes == 0)
		{
			ft_remove_node_list(&ms->ms_env, cmd->args[i], cmd);
			ft_remove_node_list(&ms->export_list, cmd->args[i], cmd);
		}
		i++;
	}
}
