/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd_home_path.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialves-m <ialves-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 11:46:53 by lpicoli-          #+#    #+#             */
/*   Updated: 2023/08/16 14:51:10 by ialves-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

bool	ft_cd_home_path(t_ms *ms, t_command *cmd, t_cd *cd)
{
	char	*tmp;

	if (ft_strcmp(cmd->args[0], "cd") == 0 && !cmd->args[1])
	{
		if (!ft_is_already_in_list("HOME", ms->ms_env))
			return (ft_error_var_start("HOME not set", "cd", 1));
		tmp = ft_return_list_info(ms->ms_env, "HOME");
		cd->oldpwd = ft_getcwd();
		ft_modify_oldpwd(ms, cd);
		if (chdir(tmp) != 0)
		{
			ft_printf("minishell: cd: %s: no such file or directory\n", tmp);
			g_exit_status = 1;
		}
		cd->pwd = tmp;
		ft_modify_pwd(ms, cd);
		ft_free(tmp);
		ft_free(cd->oldpwd);
		return (false);
	}
	else if (ft_is_home_path(cmd->args[1]) && ms->home_dir)
		cd->pwd = ft_strdup(ms->home_dir);
	else if (ft_is_home_path(cmd->args[1]))
		cd->pwd = ft_return_list_info(ms->ms_env, "HOME");
	return (true);
}
