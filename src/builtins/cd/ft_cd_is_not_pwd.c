/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd_is_not_pwd.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialves-m <ialves-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 20:47:53 by ialves-m          #+#    #+#             */
/*   Updated: 2023/08/16 14:42:58 by ialves-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

void	ft_is_not_pwd(t_ms *ms, t_command *cmd, t_cd *cd)
{
	(void)ms;
	if (!cd->pwd && !ft_is_home_path(cmd->args[1])
		&& ft_is_absolute_path(cmd->args[1]))
	{
		if (cmd->args[1][0] == '~' && cmd->args[1][1] == '/')
			cd->pwd = ft_strjoin(ft_getcwd(), ft_strtrim(cd->path, "~"));
		else
			cd->pwd = ft_strdup(cd->path);
	}
	else if (cd->path)
	{
		if (cd->pwd)
			ft_free(cd->pwd);
		if (ft_strcmp(cd->path, "..") == 0)
		{
			cd->pwd = ft_strtrim_end_quote(cd->oldpwd, '/');
			if (ft_strcmp(cd->pwd, "") == 0)
			{
				free(cd->pwd);
				cd->pwd = ft_strdup("/");
			}
		}
		else
			ft_join_old_w_new_pwd(cd);
	}
}
