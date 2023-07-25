/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpicoli- <lpicoli-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 11:46:53 by lpicoli-          #+#    #+#             */
/*   Updated: 2023/07/25 11:58:59 by lpicoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void ft_cd(t_ms *ms, t_command *cmd)
{
	t_cd cd;

	cd.i = 1;
	cd.pwd = NULL;
	cd.path = NULL;
	cd.tmp = NULL;
	if (ft_is_home_path(cmd->args[1]))
		cd.pwd = ft_return_list_info(ms->ms_env, "HOME");
	else if (ft_strcmp(cmd->args[1], "/") == 0)
		cd.pwd = ft_strdup(cmd->args[1]);
	else if (ft_strcmp(cmd->args[1], "-") == 0)
	{
		cd.pwd = ft_return_list_info(ms->ms_env, "OLDPWD");
		printf("%s\n", cd.pwd);
	}
	else if (ft_strcmp(cmd->args[1], ".") == 0)
		return;
	cd.oldpwd = ft_return_list_info(ms->ms_env, "PWD");
	ft_cd_while_is_not_pwd(ms, cmd, &cd);
	ft_free(cd.tmp);
	ft_is_not_pwd(ms, cmd, &cd);
	ft_cd_is_chdir(ms, cmd, &cd);
	free(cd.path);
	free(cd.oldpwd);
	free(cd.pwd);
}
