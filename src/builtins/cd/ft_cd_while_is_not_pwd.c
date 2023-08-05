/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd_while_is_not_pwd.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpicoli- <lpicoli-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 20:47:53 by ialves-m          #+#    #+#             */
/*   Updated: 2023/08/05 16:30:48 by lpicoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

void	ft_cd_while_is_not_pwd(t_ms *ms, t_command *cmd, t_cd *cd)
{
	(void) ms;
	while (!cd->pwd && !ft_is_home_path(cmd->args[1]) && cmd->args[cd->i])
	{
		if (!cd->tmp)
		{
			cd->tmp = ft_strdup(cmd->args[cd->i]);
			ft_free(cd->path);
			cd->path = ft_strdup(cmd->args[cd->i]);
		}
		else
		{
			ft_free(cd->path);
			cd->path = ft_strjoin(cd->tmp, cmd->args[cd->i]);
			ft_free(cd->tmp);
			cd->tmp = ft_strdup(cd->path);
		}
		cd->i++;
	}
	if (cd->path)
	{
		ft_free(cd->path);
		cd->path = ft_strtrim_end(cd->tmp, '/');
	}
}
