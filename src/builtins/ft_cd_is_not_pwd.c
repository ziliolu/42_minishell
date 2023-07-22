/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd_is_not_pwd.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialves-m <ialves-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 20:33:20 by ialves-m          #+#    #+#             */
/*   Updated: 2023/07/21 20:46:31 by ialves-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_is_not_pwd(t_ms *ms, t_command *cmd, t_cd *cd)
{
	if (!cd->pwd && !ft_is_home_path(cmd->args[1])
		&& ft_is_absolute_path(cmd->args[1]))
	{
		if (cmd->args[1][0] == '~' && cmd->args[1][1] == '/')
			cd->pwd = ft_strjoin(ft_return_list_info \
				(ms->ms_env, "HOME"), ft_strtrim(cd->path, "~"));
		else
			cd->pwd = ft_strdup(cd->path);
	}
	else if (cd->path)
	{
		if (cd->pwd)
			ft_free(cd->pwd);
		if (ft_strcmp(cd->path, "..") == 0)
			cd->pwd = ft_strtrim_end_quote(cd->oldpwd, '/');
		else
		{
			cd->tmp_path = ft_strtrim(cd->path, "/");
			cd->tmp_path_w_slash = ft_strjoin("/", cd->tmp_path);
			cd->pwd = ft_strjoin(cd->oldpwd, cd->tmp_path_w_slash);
			ft_free(cd->tmp_path);
			ft_free(cd->tmp_path_w_slash);
		}
	}	
}
