/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd_is_chdir.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpicoli- <lpicoli-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 20:51:00 by ialves-m          #+#    #+#             */
/*   Updated: 2023/07/24 12:06:14 by lpicoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_cd_is_chdir(t_ms *ms, t_command *cmd, t_cd *cd)
{
	if (chdir(cd->pwd) == 0 && ((ms->spaces_flag <= 1)
			|| ft_is_home_path(cmd->args[1])))
	{
		ft_update_list(ms->ms_env, "PWD", cd->pwd);
		ft_update_list(ms->ms_env, "OLDPWD", cd->oldpwd);
	}
	else if (cd->path[0] == '$' && ms->spaces_flag == 1)
		chdir(ft_return_list_info(ms->ms_env, "HOME"));
	else if (ms->spaces_flag > 1)
		ft_error(ms, "cd: too many arguments", NULL, 1);
	else
	{
		ft_printf("minishell: cd: %s: no such file or directory\n", cd->path);
		g_exit_status = 1;
	}
}
