/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_expand_heredoc.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialves-m <ialves-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 10:01:08 by lpicoli-          #+#    #+#             */
/*   Updated: 2023/08/01 10:29:17 by ialves-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*ft_expand_heredoc(t_lst *env, t_lst *vars, char *variable)
{
	char	*str;

	str = NULL;
	if (ft_strcmp(variable, "$") == 0)
		return (ft_strdup(variable));
	str = ft_strtrim(variable, "$");
	if (ft_strcmp(str, "?") == 0)
	{
		ft_free(str);
		return (ft_itoa(g_exit_status));
	}
	while (env)
	{
		if (ft_strcmp(str, env->name) == 0)
			return (ft_expand_while_env(env, vars, str));
		env = env->next;
	}
	while (vars)
	{
		if (ft_strcmp(str, vars->name) == 0)
			return (ft_expand_while_vars(env, vars, str));
		vars = vars->next;
	}
	free(str);
	return (ft_strdup(variable));
}
