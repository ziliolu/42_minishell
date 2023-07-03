/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpicoli- <lpicoli-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 15:45:13 by lpicoli-          #+#    #+#             */
/*   Updated: 2023/07/03 19:35:05 by lpicoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void ft_echo(t_command *cmd)
{
    char *str;
    char *tmp;
    int i;
    
    i = 1;
    str = NULL;
    tmp = NULL;
    if(cmd->args[1] && ft_strcmp(cmd->args[1], "-n") == 0)
        i++;
    
    while(cmd->args[i] != NULL)
    {  
        if(!tmp)
        {
            str = ft_strdup(cmd->args[i]);
            tmp = ft_strdup(cmd->args[i]);
        }

        if(cmd->args[i + 1] != NULL)
        {
            free(tmp);
            tmp = ft_strjoin(str, " ");
            // str = ft_strdup(tmp);
            //free(str);
            if(str)
                free(str);
            str = ft_strjoin(tmp, cmd->args[i + 1]); 
        }
        if(tmp)
            free(tmp);
        tmp = ft_strdup(str);
        i++;
    }
    // if(tmp)
    //     free(tmp);
    if(cmd->args[1] && ft_strcmp(cmd->args[1], "-n") == 0)
        ft_printf("%s", str);
    else
        ft_printf("%s\n", str);
}