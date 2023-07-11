/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpicoli- <lpicoli-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 15:45:13 by lpicoli-          #+#    #+#             */
/*   Updated: 2023/07/11 12:45:47 by lpicoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void ft_echo(t_command *cmd)
{
	char *str;
	char *tmp;
	char *final;
	int i;

	i = 1;
	str = NULL;
	tmp = NULL;
	if (cmd->args[1] && ft_strcmp(cmd->args[1], "-n") == 0)
		i++;
	
    // while (cmd->args[i])
    // {
    //     printf("args: %s\n", cmd->args[i]);
    //     i++;
    // }
    i = 1;
	while (cmd->args[i])
	{
		if (!tmp)
		{
			str = ft_strdup(cmd->args[i]);
			tmp = ft_strdup(cmd->args[i]);
		}
		if (i > 1)
		{
			if (tmp)
				free(tmp);
			tmp = ft_strjoin(" ", cmd->args[i]);
			final = ft_strjoin(str, tmp);
			if (str)
				free(str);
			str = ft_strdup(final);
			if (final)
				free(final);
		}
		i++;
	}
	if(tmp)
	    free(tmp);
	
	if (cmd->args[1] && ft_strcmp(cmd->args[1], "-n") == 0)
		ft_printf("%s", str);
	else if(cmd->args[1])
		ft_printf("%s\n", str);
	if (str)
		free (str);
	g_exit_status = 0;
}