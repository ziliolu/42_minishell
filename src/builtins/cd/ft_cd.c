/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialves-m <ialves-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 11:46:53 by lpicoli-          #+#    #+#             */
/*   Updated: 2023/08/16 15:00:09 by ialves-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

bool	ft_cd_minus_option(t_ms *ms, t_cd *cd)
{
	if (ft_is_already_in_list("OLDPWD", ms->ms_env))
		cd->pwd = ft_return_list_info(ms->ms_env, "OLDPWD");
	else if (ft_is_already_in_list("OLDPWD", *ms->vars))
		cd->pwd = ft_return_list_info(*ms->vars, "OLDPWD");
	else
	{
		ft_reset_fd_in_out(ms);
		g_exit_status = 1;
		printf("minishell: cd: OLDPWD not set\n");
		return (false);
	}
	printf("%s\n", cd->pwd);
	return (true);
}

char	*ft_find_home_in_system_env(char **str)
{
	int		i;
	char	*tmp;

	i = 0;
	while (str[i])
	{
		tmp = ft_get_list_name(str[i]);
		if (ft_strcmp("HOME", tmp) == 0)
		{
			ft_free(tmp);
			return (ft_get_list_info(str[i]));
		}
		i++;
		ft_free(tmp);
	}
	return (NULL);
}

void	ft_cd_if_til(char *tmp, t_ms *ms, t_cd *cd)
{
	tmp = ft_find_home_in_system_env(ms->system_env);
	cd->oldpwd = ft_getcwd();
	ft_modify_oldpwd(ms, cd);
	chdir(tmp);
	cd->pwd = tmp;
	ft_modify_pwd(ms, cd);
	ft_free(tmp);
	ft_free(cd->oldpwd);
}

void	ft_cd_free(t_ms *ms, t_command *cmd, t_cd *cd)
{
	ft_cd_while_is_not_pwd(ms, cmd, cd);
	ft_is_not_pwd(ms, cmd, cd);
	ft_cd_is_chdir(ms, cmd, cd);
	ft_free(cd->tmp);
	free(cd->path);
	free(cd->oldpwd);
	free(cd->pwd);
}

void	ft_cd(t_ms *ms, t_command *cmd)
{
	t_cd	cd;
	char	*tmp;

	cd.i = 1;
	cd.pwd = NULL;
	cd.path = NULL;
	cd.tmp = NULL;
	tmp = NULL;
	if (ft_strcmp(cmd->args[1], "/") == 0)
		cd.pwd = ft_strdup(cmd->args[1]);
	else if (ft_strcmp(cmd->args[1], "-") == 0)
	{
		if (!ft_cd_minus_option(ms, &cd))
			return ;
	}
	else if (ft_strcmp(cmd->args[1], "~") == 0)
	{
		ft_cd_if_til(tmp, ms, &cd);
		return ;
	}
	else if (ft_strcmp(cmd->args[1], ".") == 0
		|| !ft_cd_home_path(ms, cmd, &cd))
		return ;
	cd.oldpwd = ft_getcwd();
	ft_cd_free(ms, cmd, &cd);
}
