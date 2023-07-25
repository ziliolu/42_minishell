/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_join_old_w_new_pwd.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialves-m <ialves-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 17:20:33 by lpicoli-          #+#    #+#             */
/*   Updated: 2023/07/25 12:16:21 by ialves-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_join_old_w_new_pwd(t_cd *cd)
{
	cd->tmp_path = ft_strtrim(cd->path, "/");
	if (cd->oldpwd[ft_strlen(cd->oldpwd) - 1] == '/')
		cd->tmp_path_w_slash = ft_strdup(cd->tmp_path);
	else
		cd->tmp_path_w_slash = ft_strjoin("/", cd->tmp_path);
	cd->pwd = ft_strjoin(cd->oldpwd, cd->tmp_path_w_slash);
	ft_free(cd->tmp_path);
	ft_free(cd->tmp_path_w_slash);
}
