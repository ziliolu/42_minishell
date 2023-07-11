/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_expand.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpicoli- <lpicoli-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 12:54:35 by lpicoli-          #+#    #+#             */
/*   Updated: 2023/07/11 10:17:58 by lpicoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*ft_expand(t_lst *env, t_lst *vars, char *variable)
{
	char	*str;

	//index = i;
	
	str= ft_strtrim(variable, "$");
				
	if(ft_strcmp(str, "?") == 0)
	{
		return (ft_itoa(g_exit_status));
	}
	while (env)
	{
		if (ft_strcmp(str, env->name) == 0)
			return (ft_strdup(env->info));
		env = env->next;
	}
	while(vars)
	{
		if (ft_strcmp(str, vars->name) == 0)
			return (ft_strdup(vars->info));
		vars = vars->next;
	}
	free(str);
	//nao teria que retornar \n quando nao conseguir expandir? ex: echo $pwd
	return (NULL);
}

