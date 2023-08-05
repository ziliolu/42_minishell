/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpicoli- <lpicoli-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 17:20:33 by lpicoli-          #+#    #+#             */
/*   Updated: 2023/08/05 16:32:23 by lpicoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

void	ft_export(t_ms *ms, t_command *cmd)
{
	t_export	exp;

	exp.i = 1;
	if (!cmd->args[1])
	{
		ft_print_export(ms->export_list);
		return ;
	}
	while (cmd->args[exp.i])
	{
		ft_export_is_cmd_arg(ms, cmd, exp.i);
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
