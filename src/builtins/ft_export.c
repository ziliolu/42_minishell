/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpicoli- <lpicoli-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 17:20:33 by lpicoli-          #+#    #+#             */
/*   Updated: 2023/07/31 10:19:39 by lpicoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_export(t_ms *ms, t_command *cmd)
{
	t_export	exp;
	int			err;

	exp.i = 1;
	err = 0;
	ft_is_not_export_cmd(ms, cmd);
	while (cmd->args[exp.i])
	{
		ft_export_is_cmd_arg(ms, cmd, exp.i, &err);
		exp.str = ft_strdup(cmd->args[exp.i]);
		exp.name = ft_get_list_name(exp.str);
		exp.info = ft_get_list_info(exp.str);
		ft_export_is_in_env_list(ms, cmd, &exp);
		if (ft_strcmp(exp.name, "PATH") == 0)
		{
			ft_free_array(ms->paths);
			ms->paths = ft_split(ft_getenv(ms, "PATH"), ':');
		}
		ft_free(exp.str);
		ft_free(exp.name);
		ft_free(exp.info);
		exp.i++;
	}
}

void	ft_is_not_export_cmd(t_ms *ms, t_command *cmd)
{
	if (!cmd->args[1])
	{
		ft_print_export(ms->export_list);
		return ;
	}
	else if (!ft_is_valid_env_name(ms, cmd->args[1]))
	{
		ft_error_wo_prompt(ms, cmd->args[1], "not a valid identifier", 1);
		return ;
	}
}
