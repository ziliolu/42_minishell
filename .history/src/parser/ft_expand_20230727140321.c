/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_expand.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialves-m <ialves-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 12:54:35 by lpicoli-          #+#    #+#             */
/*   Updated: 2023/07/27 14:03:21 by ialves-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*ft_expand(t_lst *env, t_lst *vars, char *variable)
{
	char	*str;

	str = NULL;
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
	return (NULL);
}
