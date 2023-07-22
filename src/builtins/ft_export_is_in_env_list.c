/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export_is_in_env_list.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialves-m <ialves-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 17:20:33 by lpicoli-          #+#    #+#             */
/*   Updated: 2023/07/21 21:40:04 by ialves-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_export_is_in_env_list(t_ms *ms, t_command *cmd, t_export *exp)
{
	(void) cmd;
	if (ft_is_already_in_list(exp->name, ms->ms_env))
		ft_update_list(ms->ms_env, exp->name, exp->info);
	else if (ft_is_already_in_list(exp->name, *ms->vars))
	{
		if (!ft_strchr_vars(exp->str, '='))
			exp->str = ft_return_list_full_info(*ms->vars, exp->str);
		ft_add_export_node(&ms->ms_env, exp->str);
		ft_remove_node_list(ms->vars, exp->str);
	}
	else
	{
		if (ft_strchr_vars(exp->str, '='))
			ft_add_export_node(&ms->ms_env, exp->str);
	}
}
