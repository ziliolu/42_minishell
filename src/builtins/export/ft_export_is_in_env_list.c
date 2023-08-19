/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export_is_in_env_list.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpicoli- <lpicoli-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 17:20:33 by lpicoli-          #+#    #+#             */
/*   Updated: 2023/08/16 11:04:14 by lpicoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

void	ft_export_is_in_env_list(t_ms *ms, t_command *cmd, t_export *exp)
{
	char	*tmp;

	(void) cmd;
	tmp = NULL;
	if (ft_is_already_in_list(exp->name, ms->ms_env)
		&& ft_strchr(exp->str, '='))
	{
		ft_update_list(ms->ms_env, exp->name, exp->info);
		ft_update_list(ms->export_list, exp->name, exp->info);
	}
	else if (ft_is_already_in_list(exp->name, *ms->vars))
	{
		if (!ft_strchr_vars(exp->str, '='))
		{
			tmp = ft_strdup(exp->str);
			ft_free (exp->str);
			exp->str = ft_return_list_full_info(*ms->vars, tmp);
			ft_free (tmp);
		}
		ft_add_export_node(&ms->ms_env, exp->str);
		ft_add_export_node(&ms->export_list, exp->str);
		ft_remove_node_list(ms->vars, exp->str, cmd);
	}
	else
		ft_export_is_in_env_list_else(ms, cmd, exp);
}

void	ft_export_is_in_env_list_else(t_ms *ms, t_command *cmd, t_export *exp)
{
	(void) cmd;
	if (ft_strchr_vars(exp->str, '='))
	{
		ft_add_export_node(&ms->ms_env, exp->str);
		if (ft_is_already_in_list(exp->name, ms->export_list))
			ft_update_list(ms->export_list, exp->name, exp->info);
		else
			ft_add_export_node(&ms->export_list, exp->str);
	}
}
