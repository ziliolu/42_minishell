/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd_is_chdir.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpicoli- <lpicoli-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 20:51:00 by ialves-m          #+#    #+#             */
/*   Updated: 2023/08/16 13:10:23 by lpicoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

void	ft_modify_oldpwd(t_ms *ms, t_cd *cd)
{
	char	*tmp;

	tmp = NULL;
	if (ft_is_already_in_list("OLDPWD", ms->ms_env))
		ft_update_list(ms->ms_env, "OLDPWD", cd->oldpwd);
	else
	{
		if (ft_is_already_in_list("PWD", *ms->vars))
			tmp = ft_strjoin("OLDPWD=", ft_return_list_info(*ms->vars, "PWD"));
		else if (ft_is_already_in_list("PWD", ms->ms_env))
			tmp = ft_strjoin("OLDPWD=", ft_return_list_info(ms->ms_env, "PWD"));
		ft_add_node_to_list(ms, ms->vars, tmp);
		ft_free(tmp);
	}
}

void	ft_modify_pwd(t_ms *ms, t_cd *cd)
{
	char	*tmp_join;
	char	*tmp_getcwd;

	if (ft_is_already_in_list("PWD", ms->ms_env))
		ft_update_list(ms->ms_env, "PWD", cd->pwd);
	if (!ft_is_already_in_list("PWD", *ms->vars))
	{
		tmp_getcwd = ft_getcwd();
		tmp_join = ft_strjoin("PWD=", tmp_getcwd);
		ft_add_node_to_list(ms, ms->vars, tmp_join);
		ft_free (tmp_join);
		ft_free (tmp_getcwd);
	}
	else
		ft_update_list(*ms->vars, "PWD", cd->pwd);
}

void	ft_cd_is_chdir(t_ms *ms, t_command *cmd, t_cd *cd)
{
	if (chdir(cd->pwd) == 0 && ((ms->spaces_flag <= 1)
			|| ft_is_home_path(cmd->args[1])))
	{
		ft_modify_oldpwd(ms, cd);
		ft_modify_pwd(ms, cd);
	}
	else if (cd->path && cd->path[0] == '$' && ms->spaces_flag == 1)
		chdir(ft_return_list_info(ms->ms_env, "HOME"));
	else if (ms->spaces_flag > 1)
		ft_error(ms, "cd: too many arguments", NULL, 1);
	else
	{
		ft_printf("minishell: cd: %s: no such file or directory\n", cd->path);
		g_exit_status = 1;
	}
}
